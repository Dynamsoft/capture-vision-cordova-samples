package com.dynamsoft.cordova;

import android.annotation.SuppressLint;

import com.dynamsoft.cordova.handlers.BarcodeReaderHandler;
import com.dynamsoft.cordova.handlers.CameraEnhancerHandler;
import com.dynamsoft.cordova.handlers.CameraViewHandler;
import com.dynamsoft.cordova.handlers.CommonHandler;
import com.dynamsoft.dbr.BarcodeReader;
import com.dynamsoft.dbr.DBRLicenseVerificationListener;
import com.dynamsoft.dce.CameraEnhancerException;
import com.dynamsoft.dce.EnumCameraState;

import org.apache.cordova.CordovaInterface;
import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;

import org.apache.cordova.CordovaWebView;
import org.json.JSONArray;
import org.json.JSONException;

/**
 * This class echoes a string called from JavaScript.
 */
public class DynamsoftCordovaPlugin extends CordovaPlugin {
    private static String TAG = "DynamsoftCordovaPlugin";
    private BarcodeReaderHandler mBarcodeReaderHandler;
    private CameraEnhancerHandler mCameraEnhancerHandler;
    private CameraViewHandler mCameraViewHandler;

    @SuppressLint("ClickableViewAccessibility")
    @Override
    public void initialize(CordovaInterface cordova, CordovaWebView webView) {
        super.initialize(cordova, webView);
        mBarcodeReaderHandler = new BarcodeReaderHandler();
        mCameraEnhancerHandler = new CameraEnhancerHandler(cordova, webView);
        mCameraViewHandler = mCameraEnhancerHandler.mCameraViewHandler;
    }

    @Override
    public void onReset() {
        super.onReset();
        mCameraViewHandler.removeAddedView();
        try {
            if (mCameraEnhancerHandler.mCamera != null)
                if (mCameraEnhancerHandler.mCamera.getCameraState() != EnumCameraState.CLOSING
                        && mCameraEnhancerHandler.mCamera.getCameraState() != EnumCameraState.CLOSED) {
                    mCameraEnhancerHandler.mCamera.close();
                }
        } catch (CameraEnhancerException e) {
            e.printStackTrace();
        }
    }

    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) throws JSONException {
        switch (action) {
            case "coolMethod":
                String message = args.getString(0);
                this.coolMethod(message, callbackContext);
                break;

            // Common
            case "initLicense":
                CommonHandler.initLicense(args, callbackContext, cordova);
                break;

            // DBR
            case "createDbrInstance":
                mBarcodeReaderHandler.createDbrInstance(callbackContext);
                break;
            case "getVersion":
                mBarcodeReaderHandler.getVersion(callbackContext);
                break;
            case "startScanning":
                mBarcodeReaderHandler.startScanning();
                mBarcodeReaderHandler.setCameraEnhancer(mCameraEnhancerHandler.mCamera);
                break;
            case "stopScanning":
                mBarcodeReaderHandler.stopScanning();
                break;
            case "getRuntimeSettings":
                mBarcodeReaderHandler.getRuntimeSettings(callbackContext);
                break;
            case "outputSettingsToString":
                mBarcodeReaderHandler.outputSettingsToString(callbackContext);
                break;
            case "updateRuntimeSettings":
                mBarcodeReaderHandler.updateRuntimeSettings(args, callbackContext);
                break;
            case "resetRuntimeSettings":
                mBarcodeReaderHandler.resetRuntimeSettings();
                break;
            case "setTextResultListener":
                mBarcodeReaderHandler.setTextResultListener(callbackContext);
                break;

            // DCE
            case "createDceInstance":
                mCameraEnhancerHandler.createDceInstance(callbackContext);
                break;
            case "open":
                mCameraEnhancerHandler.open(callbackContext);
                break;
            case "close":
                mCameraEnhancerHandler.close(callbackContext);
                break;
            case "setTorchState":
                mCameraEnhancerHandler.setTorchState(args, callbackContext);
                break;
            case "setScanRegion":
                mCameraEnhancerHandler.setScanRegion(args, callbackContext);
                break;
            case "setScanRegionVisible":
                mCameraEnhancerHandler.setScanRegionVisible(args);
                break;

            // DCE CameraView
            case "createDceView":
                mCameraViewHandler.createDCECameraViewInstance();
                break;
            case "bindCameraViewToElement":
                mCameraViewHandler.bindCameraViewToElement(args);
                break;
            case "updateCameraViewPosition":
                mCameraViewHandler.updateCameraViewPosition(args);
                break;
            case "setCameraViewVisible":
                mCameraViewHandler.setCameraViewVisible(args);
                break;
            case "setOverlayVisible":
                mCameraViewHandler.setOverlayVisible(args);
                break;
            case "setTorchButton":
                mCameraViewHandler.setTorchButton(args);
                break;

            default:
                return false;
        }
        return true;
    }

    private void coolMethod(String message, CallbackContext callbackContext) {
        if (message != null && message.length() > 0) {
            callbackContext.success(message);
        } else {
            callbackContext.error("Expected one non-empty string argument.");
        }
    }

    private void initLicense(String license, CallbackContext callbackContext) {
        if (license != null) {

            BarcodeReader.initLicense(license, new DBRLicenseVerificationListener() {
                @Override
                public void DBRLicenseVerificationCallback(boolean b, Exception e) {
                    if (b) {
                        callbackContext.success("Init License successful.");
                    } else {
                        callbackContext.error(e.getMessage());
                    }
                }
            });
        } else {
            callbackContext.error("Expected one non-null string argument.");
        }
    }

}
