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

   Or you can install the plugin via repo URL directly.
    ```
        cordova plugin add https://github.com/dynamsoft-dbr/cordova-plugin-dbr.git
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

## Notes

If your cordova-android version is greater than 6.3.0, please 
- change repositories flatDir ``` dirs 'libs'  ``` to   ```dirs 'src/main/libs'  ``` 
- change  dependencies ``` compile 'com.android.support:support-v4:+'   ``` to   ```compile 'com.android.support:support-v4:27.1.0'  ```in file [cordova-plugin-dbr/src/android/barcodescanner.gradle](https://github.com/dynamsoft-dbr/cordova-plugin-dbr/blob/master/src/android/barcodescanner.gradle)


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
                alert("We got a barcode\n" +
                        "Result: " + result.text + "\n" +
                        "Format: " + result.format + "\n" +
                        "Cancelled: " + result.cancelled);
                },
                function (error) {
                alert("Scanning failed: " + error);
                },
                {
                "preferFrontCamera" : false, // iOS and Android
                "showFlipCameraButton" : true, // iOS and Android
                "dynamsoftlicense": "your license ",//set the Dynamsoft Barcode Reader license
                //"dynamsoftlicenseKey": "", //set the server license key
                }
            );
    }
        this.receivedEvent('deviceready');
},
```

## Technical Support

[Contact Dynamsoft](https://www.dynamsoft.com/Company/Contact.aspx)

## Screenshots

<kbd><img src="http://www.codepool.biz/wp-content/uploads/2018/04/IMG_2911.PNG" width="50%">

<kbd><img src="http://www.codepool.biz/wp-content/uploads/2018/04/IMG_2913.PNG" width="50%">
