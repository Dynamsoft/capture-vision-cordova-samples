package com.dynamsoft.cordova.handlers;

import android.annotation.SuppressLint;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.Rect;
import android.graphics.RectF;
import android.graphics.drawable.Drawable;
import android.os.Handler;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.webkit.WebView;
import android.widget.FrameLayout;

import com.dynamsoft.cordova.TorchButtonState;
import com.dynamsoft.cordova.util.BitmapUtil;
import com.dynamsoft.dce.CameraEnhancer;
import com.dynamsoft.dce.CameraEnhancerException;
import com.dynamsoft.dce.DCECameraView;

import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaWebView;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Field;

public class CameraViewHandler {
    private final CordovaInterface cordova;
    private final CordovaWebView webView;
    private View backgroundView;

    public DCECameraView mCameraView;
    private final Rect cameraViewRect = new Rect();// camera view that is visible
    private final Rect dstRect = new Rect(0, 0, 9, 16);
    private final Matrix mTransformMatrix = new Matrix();
    private TorchButtonState mTorchButtonState;
    private boolean mIsCameraViewUnderWebView;

    private final float mDensity;
    private final Handler mUiHandler;
    CameraEnhancer mCamera;

    public CameraViewHandler(CameraEnhancerHandler cameraEnhancerHandler) {
        this.cordova = cameraEnhancerHandler.cordova;
        this.webView = cameraEnhancerHandler.webView;
        mDensity = Resources.getSystem().getDisplayMetrics().density;
        mUiHandler = cameraEnhancerHandler.mUiHandler;
        mCameraView = new DCECameraView(cordova.getActivity());
        initWebViewGestureListener();
    }

    private void setBackGroundView() {
        if (backgroundView == null) {
            // init activity background
            backgroundView = new View(cordova.getContext());
            mUiHandler.post(() -> {
                backgroundView.setBackgroundColor(Color.WHITE);
                cordova.getActivity().addContentView(backgroundView, new ViewGroup.LayoutParams(
                        ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.MATCH_PARENT));
                webView.getView().bringToFront();
            });
        }
    }

    // Called in CameraEnhancerHandler.createDCEInstance()
    void bindViewToCamera() {
        mCamera.setCameraView(mCameraView);
    }

    public void bindCameraViewToElement(JSONArray args) throws JSONException {
        // setBackGroundView();
        JSONObject viewElementState = ((JSONObject) args.get(0));
        JSONObject viewPosition = viewElementState.getJSONObject("position");
        mIsCameraViewUnderWebView = viewElementState.getBoolean("underWebView");
        boolean isVisible = viewElementState.getBoolean("isVisible");

        mUiHandler.post(() -> {
            FrameLayout.LayoutParams cameraPreviewParams = new FrameLayout.LayoutParams(
                    FrameLayout.LayoutParams.MATCH_PARENT,
                    FrameLayout.LayoutParams.MATCH_PARENT);
            try {
                mCameraView.setX((int) viewPosition.getDouble("x") * mDensity);
                mCameraView.setY((int) viewPosition.getDouble("y") * mDensity);
                cameraPreviewParams.width = (int) (viewPosition.getDouble("width") * mDensity);
                cameraPreviewParams.height = (int) (viewPosition.getDouble("height") * mDensity);
            } catch (JSONException e) {
                e.printStackTrace();
            }
            WebView view = (WebView) webView.getView();
            if (mCameraView.getParent() == null) {
                ((ViewGroup) view.getParent()).addView(mCameraView, cameraPreviewParams);
            } else {
                mCameraView.setLayoutParams(cameraPreviewParams);
            }

            if (mIsCameraViewUnderWebView) {
                view.bringToFront();
                view.setBackgroundColor(Color.TRANSPARENT);
            } else {
                mCameraView.bringToFront();
            }
            mCameraView.setVisibility(isVisible ? View.VISIBLE : View.GONE);
        });
    }

    public void updateCameraViewPosition(JSONArray args) throws JSONException {
        if (!(args.get(0) instanceof JSONObject)) {
            return;
        }
        JSONObject viewPosition = (JSONObject) args.get(0);
        mUiHandler.post(() -> {
            try {
                Class<? extends DCECameraView> cls = mCameraView.getClass();
                Field mTextureViewFiled = cls.getDeclaredField("mTextureView");
                Field mScanRegionViewFiled = cls.getDeclaredField("mScanRegionView");
                Field mCanvasViewFiled = cls.getDeclaredField("mCanvasView");
                Field mBtnTorchFiled = cls.getDeclaredField("btnTorch");
                mTextureViewFiled.setAccessible(true);
                mScanRegionViewFiled.setAccessible(true);
                mCanvasViewFiled.setAccessible(true);
                mBtnTorchFiled.setAccessible(true);

                View mTextureView = (View) mTextureViewFiled.get(mCameraView);
                View mScanRegionView = (View) mScanRegionViewFiled.get(mCameraView);
                View mCanvasView = (View) mCanvasViewFiled.get(mCameraView);
                View mBtnTorch = (View) mBtnTorchFiled.get(mCameraView);

                mCameraView.setX((float) (viewPosition.getDouble("x") * mDensity));
                mCameraView.setY((float) (viewPosition.getDouble("y") * mDensity));
                FrameLayout.LayoutParams cameraPreviewParams = new FrameLayout.LayoutParams(
                        (int) (viewPosition.getDouble("width") * mDensity),
                        (int) (viewPosition.getDouble("height") * mDensity));
                mCameraView.setLayoutParams(cameraPreviewParams);
                mCameraView.requestLayout();
                if (mTextureView != null) {
                    mTextureView.requestLayout();
                }
                if (mScanRegionView != null) {
                    mScanRegionView.requestLayout();
                }
                if (mCanvasView != null) {
                    mCanvasView.requestLayout();
                }
                if (mBtnTorch != null) {
                    mBtnTorch.requestLayout();
                }
            } catch (JSONException | IllegalAccessException | NoSuchFieldException e) {
                e.printStackTrace();
            }
        });
    }

    public void setCameraViewVisible(JSONArray args) throws JSONException {
        mUiHandler.post(new Runnable() {
            @Override
            public void run() {
                try {
                    mCameraView.setVisibility(args.getBoolean(0) ? View.VISIBLE : View.GONE);
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public void setOverlayVisible(JSONArray args) throws JSONException {
        mCameraView.setOverlayVisible(args.getBoolean(0));
    }

    public void setTorchButton(JSONArray args) throws JSONException {
        JSONObject torchButton = args.getJSONObject(0);
        boolean isVisible = torchButton.getBoolean("visible");
        if (mTorchButtonState == null) {
            mTorchButtonState = new TorchButtonState();
        }
        mTorchButtonState.setVisible(isVisible);
        if (isVisible) {
            JSONObject location = torchButton.isNull("location") ? null : torchButton.getJSONObject("location");
            android.graphics.Point startPoint;
            int width;
            int height;
            if (location != null) {
                int x = (location.isNull("x")) ? 25 : location.getInt("x");
                int y = (location.isNull("y")) ? 100 : location.getInt("y");
                startPoint = new android.graphics.Point(x, y);
                width = (location.isNull("width")) ? 45 : location.getInt("width");
                height = (location.isNull("height")) ? 45 : location.getInt("height");
            } else {
                // Default location. Unit is dp.
                startPoint = new android.graphics.Point(25, 100);
                width = 45;
                height = 45;
            }
            String torchOnImage = (torchButton.isNull("torchOnImage")) ? null
                    : torchButton.getString("torchOnImage");
            String torchOffImage = (torchButton.isNull("torchOffImage")) ? null
                    : torchButton.getString("torchOffImage");
            Drawable torchOnDrawable = null;
            Drawable torchOffDrawable = null;
            if (torchOnImage != null) {
                try {
                    InputStream is = cordova.getContext().getAssets().open("www/" + torchOnImage);
                    torchOnDrawable = BitmapUtil.InputStreamToDrawable(is);
                    is.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (torchOffImage != null) {
                try {
                    InputStream is = cordova.getContext().getAssets().open("www/" + torchOffImage);
                    torchOffDrawable = BitmapUtil.InputStreamToDrawable(is);
                    is.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }

            mTorchButtonState.setLocationInCameraView(startPoint.x * mDensity, startPoint.y * mDensity,
                    width * mDensity,
                    height * mDensity);

            mCameraView.setTorchButton(startPoint, width, height, torchOnDrawable, torchOffDrawable);
            mCameraView.setTorchButtonVisible(true);
        } else {
            mCameraView.setTorchButtonVisible(false);
        }
    }

    public void removeAddedView() {
        removeCameraView();
        // Don't remove white background.
        // removeBackgroundView();
    }

    private void removeBackgroundView() {
        mUiHandler.post(() -> {
            if (backgroundView != null && backgroundView.getParent() != null) {
                ((ViewGroup) backgroundView.getParent()).removeView(backgroundView);
            }
        });
    }

    private void removeCameraView() {
        mUiHandler.post(() -> {
            if (mCameraView != null && mCameraView.getParent() != null) {
                ((ViewGroup) mCameraView.getParent()).removeView(mCameraView);
            }
        });
    }

    @SuppressLint("ClickableViewAccessibility")
    private void initWebViewGestureListener() {
        GestureDetector gestureDetector = new GestureDetector(cordova.getContext(),
                new GestureDetector.SimpleOnGestureListener() {
                    @Override
                    public boolean onSingleTapUp(MotionEvent e) {
                        if (mCameraView != null && mCameraView.getWidth() != 0 && mCameraView.getHeight() != 0
                                && mCamera != null && mIsCameraViewUnderWebView) {
                            // relative position to the original point of cameraView
                            float touchXInCameraView = e.getX() - mCameraView.getX();
                            float touchYInCameraView = e.getY() - mCameraView.getY();

                            boolean ifTapOnCameraView = touchXInCameraView <= mCameraView.getWidth()
                                    && touchYInCameraView <= mCameraView.getHeight();

                            if (ifTapOnCameraView) {
                                boolean ifTapOnTorchBtn = false;
                                if (mTorchButtonState != null && mTorchButtonState.isVisible) {
                                    float offsetX = mTorchButtonState.locationInCameraView.right
                                            - mCameraView.getWidth() < 0 ? 0
                                                    : -(mTorchButtonState.locationInCameraView.right
                                                            - mCameraView.getWidth());
                                    float offsetY = mTorchButtonState.locationInCameraView.bottom
                                            - mCameraView.getHeight() < 0 ? 0
                                                    : -(mTorchButtonState.locationInCameraView.bottom
                                                            - mCameraView.getHeight());
                                    RectF newRectF = new RectF(mTorchButtonState.locationInCameraView);
                                    if (offsetX != 0 || offsetY != 0) {
                                        newRectF.offset(offsetX, offsetY);
                                    }
                                    ifTapOnTorchBtn = mTorchButtonState.isVisible
                                            && newRectF.contains(touchXInCameraView,
                                                    touchYInCameraView);
                                }
                                if (ifTapOnTorchBtn) {
                                    // TODO: 2022/7/14 temporary way to answering to webview touch event
                                    // for torch button(use reflection)
                                    try {
                                        Class<? extends CameraEnhancer> dceCls = mCamera.getClass();
                                        Field currentTorchStateField = dceCls.getDeclaredField("mCurrentTorchState");
                                        currentTorchStateField.setAccessible(true);
                                        Enum currentTorchState = ((Enum) currentTorchStateField.get(mCamera));
                                        if (currentTorchState.ordinal() == 0) {
                                            // current torch state is off, need to turn on torch after tap button
                                            mCamera.turnOnTorch();
                                        } else {
                                            // current torch state is on, need to turn off torch after tap button
                                            mCamera.turnOffTorch();
                                        }
                                    } catch (NoSuchFieldException | IllegalAccessException
                                            | CameraEnhancerException noSuchFieldException) {
                                        noSuchFieldException.printStackTrace();
                                    }
                                } else {
                                    if (Resources.getSystem()
                                            .getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE) {
                                        dstRect.set(0, 0, 16, 9);
                                    } else if (Resources.getSystem()
                                            .getConfiguration().orientation == Configuration.ORIENTATION_PORTRAIT) {
                                        dstRect.set(0, 0, 9, 16);
                                    }
                                    mCameraView.getDrawingRect(cameraViewRect);
                                    mTransformMatrix.setRectToRect(new RectF(cameraViewRect), new RectF(dstRect),
                                            Matrix.ScaleToFit.FILL);
                                    float[] dst = new float[2];
                                    mTransformMatrix.mapPoints(dst,
                                            new float[] { touchXInCameraView, touchYInCameraView });
                                    try {
                                        mCamera.setFocus(dst[0] / dstRect.width(), dst[1] / dstRect.height());
                                    } catch (CameraEnhancerException cameraEnhancerException) {
                                        cameraEnhancerException.printStackTrace();
                                    }
                                }
                            }
                        }

                        return false;
                    }
                });
        webView.getView().setOnTouchListener((v, event) -> gestureDetector.onTouchEvent(event));
    }
}
