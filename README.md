# Dynamsoft Barcode Reader Cordova Plugin for iOS and Android

Use the Dynamsoft Barcode Reader Cordova Plugin to quickly develop mobile apps for barcode reading (iOS and Android). 

To learn more about Dynamsoft Barcode Reader, please visit http://www.dynamsoft.com/Products/Dynamic-Barcode-Reader.aspx.

## License

You can request for a free trial license online. [Get a trial license >](https://www.dynamsoft.com/CustomerPortal/Portal/Triallicense.aspx)

## Installation

1. Install **Cordova** via **npm**.

    ```  
        npm install -g cordova
    ```

2. Download the source code and add the plugin via local path.

    ```
        cordova plugin add <local-path>/cordova-plugin-dbr
    ```
    
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

## Others ##
If your cordova-android version > 6.3.0, please change repositories flatDir ``` dirs 'libs'  ``` to   ```dirs 'src/main/libs'  ``` and change  dependencies ``` compile 'com.android.support:support-v4:+'   ``` to   ```compile 'com.android.support:support-v4:27.1.0'  ```in the file [cordova-plugin-dbr/src/android/barcodescanner.gradle](https://github.com/dynamsoft-dbr/cordova-plugin-dbr/blob/master/src/android/barcodescanner.gradle) 


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
