package com.dynamsoft.cordova.handlers;

import android.os.Handler;
import android.os.Looper;

import com.dynamsoft.dce.RegionDefinition;
import com.dynamsoft.dce.CameraEnhancer;
import com.dynamsoft.dce.CameraEnhancerException;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaWebView;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class CameraEnhancerHandler {
    public CordovaInterface cordova;
    public CordovaWebView webView;

    public CameraEnhancer mCamera;
    public CameraViewHandler mCameraViewHandler;
    Handler mUiHandler = new Handler(Looper.getMainLooper());

    public CameraEnhancerHandler(CordovaInterface cordova, CordovaWebView webView) {
        this.cordova = cordova;
        this.webView = webView;
        mCameraViewHandler = new CameraViewHandler(this);
    }

    public void createDceInstance(CallbackContext callbackContext) {
        // init CameraEnhancer and DCECameraView
        mCamera = new CameraEnhancer(cordova.getActivity());
        if(mCameraViewHandler.mCameraView != null) {
            mCamera.setCameraView(mCameraViewHandler.mCameraView);
        }
        try {
            mCameraViewHandler.mCamera = this.mCamera;
        } catch (Exception e) {
            callbackContext.error(e.getMessage());
            e.printStackTrace();
        }
        callbackContext.success();
    }

    public void open(CallbackContext callbackContext) {
        mUiHandler.post(new Runnable() {
            @Override
            public void run() {
                try {
                    mCamera.open();
                } catch (CameraEnhancerException e) {
                    callbackContext.error(e.getMessage());
                    e.printStackTrace();
                }
                callbackContext.success();
            }
        });

    }

    public void close(CallbackContext callbackContext) {
        mUiHandler.post(new Runnable() {
            @Override
            public void run() {
                try {
                    mCamera.close();
                } catch (CameraEnhancerException e) {
                    callbackContext.error(e.getMessage());
                    e.printStackTrace();
                }
                callbackContext.success();
            }
        });
    }

    public void setTorchState(JSONArray args, CallbackContext callbackContext) throws JSONException {
        try {
            if (args.getInt(0) == 1) {
                mCamera.turnOnTorch();
            } else {
                mCamera.turnOffTorch();
            }
        } catch (CameraEnhancerException e) {
            callbackContext.error(e.getMessage());
        }
        callbackContext.success();
    }

    public void setScanRegion(JSONArray args, CallbackContext callbackContext) throws JSONException {
        if (args.get(0).equals(null)) {
            try {
                mCamera.setScanRegion(null);
            } catch (CameraEnhancerException e) {
                callbackContext.error(e.getMessage());
            }
        } else {
            JSONObject region = args.getJSONObject(0);
            int regionLeft = 0, regionTop = 0, regionRight = 100, regionBottom = 100, regionMeasuredByPercentage = 1;
            if (!region.isNull("regionLeft")) {
                regionLeft = region.getInt("regionLeft");
            }
            if (!region.isNull("regionTop")) {
                regionTop = region.getInt("regionTop");
            }
            if (!region.isNull("regionRight")) {
                regionRight = region.getInt("regionRight");
            }
            if (!region.isNull("regionBottom")) {
                regionBottom = region.getInt("regionBottom");
            }
            if (!region.isNull("regionMeasuredByPercentage")) {
                regionMeasuredByPercentage = region.getInt("regionMeasuredByPercentage");
            }

            RegionDefinition regionDefinition = new RegionDefinition();
            regionDefinition.regionLeft = regionLeft;
            regionDefinition.regionRight = regionRight;
            regionDefinition.regionTop = regionTop;
            regionDefinition.regionBottom = regionBottom;
            regionDefinition.regionMeasuredByPercentage = regionMeasuredByPercentage;
            try {
                mCamera.setScanRegion(regionDefinition);
            } catch (CameraEnhancerException e) {
                callbackContext.error(e.getMessage());
            }
        }
        callbackContext.success();
    }

    public void setScanRegionVisible(JSONArray args) throws JSONException {
        boolean isVisible = args.getBoolean(0);
        mCamera.setScanRegionVisible(isVisible);
    }
}
