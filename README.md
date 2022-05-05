# Dynamsoft Barcode Reader Cordova Plugin for iOS and Android

Use the Dynamsoft Barcode Reader Cordova Plugin to quickly develop mobile apps for barcode reading (iOS and Android). 

To learn more about Dynamsoft Barcode Reader, please visit http://www.dynamsoft.com/Products/Dynamic-Barcode-Reader.aspx.

## What You Should Know
- [![](https://img.shields.io/badge/Download-Offline%20SDK-orange)](https://www.dynamsoft.com/barcode-reader/downloads)
- [![](https://img.shields.io/badge/Get-30--day%20FREE%20Trial%20License-blue)](https://www.dynamsoft.com/customer/license/trialLicense/?product=dbr)

## Installation

1. Install **Cordova** via **npm**.

    ```  
        npm install -g cordova
    ```

2. Create the Cordova app and add the mobile platform(s) that you would like. Please note that the DBR Cordova Plugin does not support a browser implementation. For more info on how to create a Cordova app, please refer to the [Cordova documentation](https://cordova.apache.org/docs/en/latest/guide/cli/index.html)

3. Download the plugin's source code by cloning this repo or downloading it as a ZIP. 

4. Add the plugin via the local path of the source code you just downloaded.

    ```
        cordova plugin add <local-path>/cordova-plugin-dbr
    ```
5. Now for the implementation in the `www` folder, which should include a `index.html` file as well as a `js/index.js` file, please see the example below for reference.

6. For the `iOS` platform, the DynamsoftBarcodeReader.framework that is included in the `platforms/ios/<project name>.xcodeproj` must be set to `Embed & Sign` in the General settings of the xcodeproj. This is important or it will result in an error.
> Please note that when using Cordova 10 or higher on iOS, the following extra steps are required:
> - `Photos.framework` must be manually added in the xcworkspace project under platforms/iOS
> - Info.plist must be updated with the Privacy Camera and Privacy Photo properties to allow for camera usage and photo library access.
> - You might need to manually change C++ language dialect of the build settings (in the xcworkspace) to GNU+11 if it is not the default.
> - Once all these changes are done, the app successfully deploys via `cordova run ios --device` given that your test device is connected to your Mac machine.

> IMPORTANT NOTE: Our SDK is not compatible with simulators as it requires the camera to operate. If you attempt to emulate the Cordova app on a simulator, you will most likely be faced with errors, which is the expected outcome.
    
## Supported Platforms

- iOS
- Android

## Supported Barcode Types

The following barcode types are currently supported:

* Code 39
* Code 93
* Code 128
* Codabar
* EAN-8
* EAN-13
* UPC-A
* UPC-E
* Interleaved 2 of 5 (ITF)
* Industrial 2 of 5 (Code 2 of 5 Industry, Standard 2 of 5, Code 2 of 5)
* ITF-14 
* QRCode
* DataMatrix
* PDF417
* GS1 DataBar
* Maxicode
* Micro PDF417
* Micro QR
* PatchCode
* GS1 Composite
* Postal Code
* Dot Code

## Important Notes ##
- If your cordova-android version > 6.3.0, please change repositories flatDir ``` dirs 'libs'  ``` to   ```dirs 'src/main/libs'  ``` and change  dependencies ``` compile 'com.android.support:support-v4:+'   ``` to   ```compile 'com.android.support:support-v4:27.1.0'  ```in the file [cordova-plugin-dbr/src/android/barcodescanner.gradle](https://github.com/dynamsoft-dbr/cordova-plugin-dbr/blob/master/src/android/barcodescanner.gradle)

- If you encounter an error while deploying your Cordova application to the App Store (iOS), please note that it could be related to a known issue regarding unsupported architectures. This is because the DBR Cordova Plugin currently uses the `.framework` instead of the newly created `.xcframework`. To resolve this error currently, please refer to this [page](https://www.dynamsoft.com/barcode-reader/programming/objectivec-swift/user-guide.html?ver=latest#unsupported-architectures-error-when-building-and-releasing-the-application-for-the-app-store). 

## Example

**index.html**

```html
<body>
    <div class="app">
        <div id="deviceready">
            <button id="scan">scan barcode</button>
        </div>
    </div>
    <script type="text/javascript" src="cordova.js"></script>
    <script type="text/javascript" src="js/index.js"></script>
</body>
```

**index.js**

```js
onDeviceReady: function() {
    document.getElementById("scan").onclick = function() {
        cordova.plugins.barcodeScanner.scan(
            function (result) {
                alert("Results: \n" +
                       result.text + "\n" +
                       result.format + "\n" +
                      "Cancelled: " + result.cancelled);
            },
            function (error) {
                alert("Scanning failed: " + error);
            },
            {
                "preferFrontCamera" : false, // iOS and Android
                "showFlipCameraButton" : true, // iOS and Android
                
                // Please use one of the following three methods to set the license accordingly. If you set one of them, make sure the other two are either empty or commented out.
                "dynamsoftlicense": "your license",// If you are using a trial license or a long key, please insert your license here.
                //"dynamsoftlicenseKey": "", // If you purchased a full license and are using version 7.x or below, please insert the full license key here.
                //"handshakeCode": "your handshakeCode", // If you purchased a full license and are using version 8.x or above, please insert the handshakeCode here.
                
                // The following properties are valid only when you use "handshakeCode" to activate the SDK. They are optional and you can leave the commented code there. But if you would like to set these properties, please refer to the API list here https://www.dynamsoft.com/barcode-reader/programming/android/api-reference/class/DMLTSConnectionParameters.html?ver=latest#attributes
                //"mainServerURL": "", 
                //"standbyServerURL": "", 
                //"sessionPassword": "", 
                //"uuidGenerationMethod": 1, 
                //"maxBufferDays": 7, 
                //"chargeWay": 0, 
                //"limitedLicenseModules": "[1,2,3]"
            }
        );
    }
    this.receivedEvent('deviceready');
},
```

## Technical Support

[Contact Dynamsoft](https://www.dynamsoft.com/Company/Contact.aspx)

## Screenshots

<kbd><img src="https://www.dynamsoft.com/codepool/img/2018/04/IMG_2911.PNG" width="50%">

<kbd><img src="https://www.dynamsoft.com/codepool/img/2018/04/IMG_2913.PNG" width="50%">
