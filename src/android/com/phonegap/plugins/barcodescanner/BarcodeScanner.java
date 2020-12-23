package com.phonegap.plugins.barcodescanner;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import android.Manifest;
import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.content.pm.PackageManager;

import org.apache.cordova.CordovaPlugin;
import org.apache.cordova.CallbackContext;
import org.apache.cordova.PluginResult;
import org.apache.cordova.PermissionHelper;

import com.dynamsoft.demo.dynamsoftbarcodereaderdemo.DBR;

/**
 * This calls out to the Dynamsoft barcode reader and returns the result.
 *
 * @sa https://github.com/apache/cordova-android/blob/master/framework/src/org/apache/cordova/CordovaPlugin.java
 */
public class BarcodeScanner extends CordovaPlugin {
    public static final int REQUEST_CODE = 0x0ba7c0de;

    private static final String SCAN = "scan";
    private static final String CANCELLED = "cancelled";
    private static final String FORMAT = "format";
    private static final String TEXT = "text";
    private static final String DATA = "data";
    private static final String TYPE = "type";
    private static final String SMS_TYPE = "SMS_TYPE";

    private static final String LOG_TAG = "BarcodeScanner";

    private String [] permissions = { Manifest.permission.CAMERA };

    private JSONArray requestArgs;
    private CallbackContext callbackContext;

    /**
     * Constructor.
     */
    public BarcodeScanner() {
    }

    /**
     * Executes the request.
     *
     * This method is called from the WebView thread. To do a non-trivial amount of work, use:
     *     cordova.getThreadPool().execute(runnable);
     *
     * To run on the UI thread, use:
     *     cordova.getActivity().runOnUiThread(runnable);
     *
     * @param action          The action to execute.
     * @param args            The exec() arguments.
     * @param callbackContext The callback context used when calling back into JavaScript.
     * @return                Whether the action was valid.
     *
     * @sa https://github.com/apache/cordova-android/blob/master/framework/src/org/apache/cordova/CordovaPlugin.java
     */
    @Override
    public boolean execute(String action, JSONArray args, CallbackContext callbackContext) {
        this.callbackContext = callbackContext;
        this.requestArgs = args;

        if (action.equals(SCAN)) {

            //android permission auto add
            if(!hasPermisssion()) {
              requestPermissions(0);
            } else {
              scan(args);
            }
        } else {
            return false;
        }
        return true;
    }

    /**
     * Starts an intent to scan and decode a barcode.
     */
    public void scan(final JSONArray args) {

        final CordovaPlugin that = this;

        cordova.getThreadPool().execute(new Runnable() {
            public void run() {

                Intent intentScan = new Intent(that.cordova.getActivity().getBaseContext(), DBR.class);
                intentScan.setAction("com.dynamsoft.dbr");

                // avoid calling other phonegap apps
                intentScan.setPackage(that.cordova.getActivity().getApplicationContext().getPackageName());
				String strLicense ="",strLicenseKey="",handshakeCode ="",mainServerURL="",standbyServerURL ="",sessionPassword="",limitedLicenseModules="";
				int uuidGenerationMethod = 1, maxBufferDays = 7, chargeWay = 0;
				try{
                    JSONObject json = args.getJSONObject(0);
                    if (json.has("dynamsoftlicense")){
                        strLicense = json.getString("dynamsoftlicense");
                    }
                    if (json.has("dynamsoftlicenseKey")){
                        strLicenseKey = json.getString("dynamsoftlicenseKey");
                    }
                    if (json.has("handshakeCode")){
                        handshakeCode = json.getString("handshakeCode");
                    }
                    if (json.has("mainServerURL")){
                        mainServerURL = json.getString("mainServerURL");
                    }
                    if (json.has("standbyServerURL")){
                        standbyServerURL = json.getString("standbyServerURL");
                    }
                    if (json.has("sessionPassword")){
                        sessionPassword = json.getString("sessionPassword");
                    }
                    if (json.has("uuidGenerationMethod")){
                        uuidGenerationMethod = json.getInt("uuidGenerationMethod");
                    }
                    if (json.has("maxBufferDays")){
                        maxBufferDays = json.getInt("maxBufferDays");
                    }
                    if (json.has("chargeWay")){
                        chargeWay = json.getInt("chargeWay");
                    }
                    if (json.has("limitedLicenseModules")){
                        limitedLicenseModules = json.getString("limitedLicenseModules");
                    }
				}catch(Exception e){
					Log.d(LOG_TAG, "dynamsoftlicense:error");
				}
                that.cordova.startActivityForResult(that, intentScan.putExtra("barcodeLicense",strLicense)
                        .putExtra("barcodeLicenseKey",strLicenseKey)
                        .putExtra("handshakeCode",handshakeCode)
                        .putExtra("mainServerURL",mainServerURL)
                        .putExtra("standbyServerURL",standbyServerURL)
                        .putExtra("sessionPassword",sessionPassword)
                        .putExtra("uuidGenerationMethod",uuidGenerationMethod)
                        .putExtra("maxBufferDays",maxBufferDays)
                        .putExtra("chargeWay",chargeWay)
                        .putExtra("limitedLicenseModules",limitedLicenseModules), REQUEST_CODE);
            }
        });
    }

    /**
     * Called when the barcode scanner intent completes.
     *
     * @param requestCode The request code originally supplied to startActivityForResult(),
     *                       allowing you to identify who this result came from.
     * @param resultCode  The integer result code returned by the child activity through its setResult().
     * @param intent      An Intent, which can return result data to the caller (various data can be attached to Intent "extras").
     */
    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent intent) {
        if (requestCode == REQUEST_CODE && this.callbackContext != null) {
            if (resultCode == Activity.RESULT_OK) {
                JSONObject obj = new JSONObject();
                try {
                    obj.put(TEXT, intent.getStringExtra("SCAN_RESULT"));
                    obj.put(FORMAT, intent.getStringExtra("SCAN_RESULT_FORMAT"));
                    obj.put(CANCELLED, false);
                } catch (JSONException e) {
                    Log.d(LOG_TAG, "This should never happen");
                }
                //this.success(new PluginResult(PluginResult.Status.OK, obj), this.callback);
                this.callbackContext.success(obj);
            } else if (resultCode == Activity.RESULT_CANCELED) {
                JSONObject obj = new JSONObject();
                try {
                    obj.put(TEXT, "");
                    //obj.put(FORMAT, "");
                    obj.put(CANCELLED, true);
                } catch (JSONException e) {
                    Log.d(LOG_TAG, "This should never happen");
                }
                //this.success(new PluginResult(PluginResult.Status.OK, obj), this.callback);
                this.callbackContext.success(obj);
            } else {
                //this.error(new PluginResult(PluginResult.Status.ERROR), this.callback);
                this.callbackContext.error("Unexpected error");
            }
        }
    }

    /**
     * check application's permissions
     */
   public boolean hasPermisssion() {
       for(String p : permissions)
       {
           if(!PermissionHelper.hasPermission(this, p))
           {
               return false;
           }
       }
       return true;
   }

    /**
     * We override this so that we can access the permissions variable, which no longer exists in
     * the parent class, since we can't initialize it reliably in the constructor!
     *
     * @param requestCode The code to get request action
     */
   public void requestPermissions(int requestCode)
   {
       PermissionHelper.requestPermissions(this, requestCode, permissions);
   }

   /**
   * processes the result of permission request
   *
   * @param requestCode The code to get request action
   * @param permissions The collection of permissions
   * @param grantResults The result of grant
   */
  public void onRequestPermissionResult(int requestCode, String[] permissions,
                                         int[] grantResults) throws JSONException
   {
       PluginResult result;
       for (int r : grantResults) {
           if (r == PackageManager.PERMISSION_DENIED) {
               Log.d(LOG_TAG, "Permission Denied!");
               result = new PluginResult(PluginResult.Status.ILLEGAL_ACCESS_EXCEPTION);
               this.callbackContext.sendPluginResult(result);
               return;
           }
       }

       switch(requestCode)
       {
           case 0:
               scan(this.requestArgs);
               break;
       }
   }

    /**
     * This plugin launches an external Activity when the camera is opened, so we
     * need to implement the save/restore API in case the Activity gets killed
     * by the OS while it's in the background.
     */
    public void onRestoreStateForActivityResult(Bundle state, CallbackContext callbackContext) {
        this.callbackContext = callbackContext;
    }

}
