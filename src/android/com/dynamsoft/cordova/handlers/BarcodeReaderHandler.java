package com.dynamsoft.cordova.handlers;

import android.util.Base64;

import com.dynamsoft.dbr.BarcodeReader;
import com.dynamsoft.dbr.BarcodeReaderException;
import com.dynamsoft.dbr.EnumBarcodeFormat_2;
import com.dynamsoft.dbr.EnumConflictMode;
import com.dynamsoft.dbr.EnumPresetTemplate;
import com.dynamsoft.dbr.ImageData;
import com.dynamsoft.dbr.LocalizationResult;
import com.dynamsoft.dbr.Point;
import com.dynamsoft.dbr.PublicRuntimeSettings;
import com.dynamsoft.dbr.TextResult;
import com.dynamsoft.dbr.TextResultListener;
import com.dynamsoft.dce.CameraEnhancer;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class BarcodeReaderHandler {
    public BarcodeReader mReader;

    public void createDbrInstance(CallbackContext callbackContext) {
        if (mReader == null) {
            try {
                mReader = new BarcodeReader();
            } catch (BarcodeReaderException e) {
                callbackContext.error(e.getMessage());
                e.printStackTrace();
            }
        }
        callbackContext.success();
    }

    public void getVersion(CallbackContext callbackContext) {
        callbackContext.success(BarcodeReader.getVersion());
    }

    public void startScanning() {
        mReader.startScanning();
    }

    public void stopScanning() {
        mReader.stopScanning();
    }

    public void getRuntimeSettings(CallbackContext callbackContext) {
        try {
            PublicRuntimeSettings settings = mReader.getRuntimeSettings();
            JSONObject jsonObject = new JSONObject();
            jsonObject.put("barcodeFormatIds", settings.barcodeFormatIds);
            jsonObject.put("barcodeFormatIds_2", settings.barcodeFormatIds_2);
            jsonObject.put("expectedBarcodesCount", settings.expectedBarcodesCount);
            jsonObject.put("timeout", settings.timeout);
            callbackContext.success(jsonObject);
        } catch (BarcodeReaderException | JSONException e) {
            callbackContext.error(e.getMessage());
            e.printStackTrace();
        }
    }

    public void outputSettingsToString(CallbackContext callbackContext) {
        try {
            String settings = mReader.outputSettingsToString("");
            callbackContext.success(settings);
        } catch (BarcodeReaderException ignored) {
        }
    }

    public void updateRuntimeSettings(JSONArray args, CallbackContext callbackContext) throws JSONException {
        Object settings = args.get(0);
        try {
            if (settings instanceof String) {
                mReader.initRuntimeSettingsWithString((String) settings, EnumConflictMode.CM_OVERWRITE);
            } else if (settings instanceof Integer) {
                mReader.updateRuntimeSettings(EnumPresetTemplate.fromValue((int) settings));
            } else if (settings instanceof JSONObject) {
                PublicRuntimeSettings s = mReader.getRuntimeSettings();
                if (!((JSONObject) settings).isNull("barcodeFormatIds")) {
                    s.barcodeFormatIds = ((JSONObject) settings).getInt("barcodeFormatIds");
                }
                if (!((JSONObject) settings).isNull("barcodeFormatIds_2")) {
                    s.barcodeFormatIds_2 = ((JSONObject) settings).getInt("barcodeFormatIds_2");
                }
                if (!((JSONObject) settings).isNull("expectedBarcodesCount")) {
                    s.expectedBarcodesCount = ((JSONObject) settings).getInt("expectedBarcodesCount");
                }
                if (!((JSONObject) settings).isNull("timeout")) {
                    s.timeout = ((JSONObject) settings).getInt("timeout");
                }
                mReader.updateRuntimeSettings(s);
            }
        } catch (BarcodeReaderException e) {
            callbackContext.error(e.getMessage());
        }
        callbackContext.success();
    }

    public void resetRuntimeSettings() {
        try {
            mReader.resetRuntimeSettings();
        } catch (BarcodeReaderException e) {
            e.printStackTrace();
        }
    }

    public void setTextResultListener(CallbackContext callbackContext) {
        mReader.setTextResultListener(new TextResultListener() {
            @Override
            public void textResultCallback(int i, ImageData imageData, TextResult[] textResults) {
                try {
                    PluginResult pluginResult = null;
                    pluginResult = new PluginResult(PluginResult.Status.OK,
                            textResults != null && textResults.length > 0 ? handleResults(textResults)
                                    : new JSONArray());
                    pluginResult.setKeepCallback(true);
                    callbackContext.sendPluginResult(pluginResult);
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            }
        });
    }

    private JSONArray handleResults(TextResult[] barcodes) throws JSONException {

        JSONArray barcodesList = new JSONArray();

        for (int i = 0; i < barcodes.length; i++) {
            TextResult barcode = barcodes[i];
            JSONObject jsonBarcode = new JSONObject();

            if (barcode.barcodeFormat_2 != EnumBarcodeFormat_2.BF2_NULL) {
                jsonBarcode.put("barcodeFormatString", barcode.barcodeFormatString_2);
            } else {
                jsonBarcode.put("barcodeFormatString", barcode.barcodeFormatString);
            }
            jsonBarcode.put("barcodeText", barcode.barcodeText);
            String bytesBase64 = Base64.encodeToString(barcode.barcodeBytes, Base64.DEFAULT);
            jsonBarcode.put("barcodeBytes", bytesBase64);
            jsonBarcode.put("barcodeLocation", handleLocationResult(barcode.localizationResult));
            barcodesList.put(jsonBarcode);
        }
        return barcodesList;
    }

    private JSONObject handleLocationResult(LocalizationResult result) throws JSONException {
        if (result == null) {
            return null;
        }
        JSONObject location = new JSONObject();
        location.put("angle", result.angle);
        location.put("quadrilateral", handleQuadrilateral(result.resultPoints));
        return location;
    }

    private JSONObject handleQuadrilateral(Point[] points) throws JSONException {
        if (points == null) {
            return null;
        }
        JSONObject quadrilateral = new JSONObject();
        quadrilateral.put("points", handlePoints(points));
        return quadrilateral;
    }

    private JSONArray handlePoints(Point[] points) throws JSONException {
        if (points == null) {
            return null;
        }
        JSONArray pointArray = new JSONArray();
        for (int i = 0; i < 4; i++) {
            pointArray.put(handleSinglePoint(points[i]));
        }
        return pointArray;
    }

    private JSONObject handleSinglePoint(Point point) throws JSONException {
        JSONObject pointMap = new JSONObject();
        pointMap.put("x", point.x);
        pointMap.put("y", point.y);
        return pointMap;
    }

    public void setCameraEnhancer(CameraEnhancer cameraEnhancer) {
        if(cameraEnhancer != null) {
            mReader.setCameraEnhancer(cameraEnhancer);
        }
    }
}
