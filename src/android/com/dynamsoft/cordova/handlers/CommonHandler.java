package com.dynamsoft.cordova.handlers;


import com.dynamsoft.dbr.BarcodeReader;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaInterface;
import org.json.JSONArray;
import org.json.JSONException;

public class CommonHandler {
    public  static void initLicense(JSONArray args, CallbackContext callbackContext, CordovaInterface cordova) throws JSONException {
        String license = args.getString(0);
        cordova.getThreadPool().execute(() -> {
            if (license != null) {
                BarcodeReader.initLicense(license, (b, e) -> {
                    if (b) {
                        callbackContext.success();
                    } else {
                        callbackContext.error(e.getMessage());
                    }
                });
            } else {
                callbackContext.error("Expected one non-null string argument.");
            }
        });
    }
}
