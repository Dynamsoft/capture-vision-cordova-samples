
document.addEventListener('deviceready', onDeviceReady, false);
document.addEventListener('resume', onResume, false);
document.addEventListener('pause', onPause, false);

var dbr
var dce

const cameraViewElement = document.getElementById("camera_view")

async function onDeviceReady() {

    dbr = await Dynamsoft.DCVBarcodeReader.createInstance()

    dbr.updateRuntimeSettings(Dynamsoft.EnumDBRPresetTemplate.VIDEO_SPEED_FIRST)

    dbr.addResultListener((results) => {
        let resultElement = document.getElementById('show_result');
        var resultStr = ""
        if (results && results.length > 0) {
            for (i = 0; i < results.length; i++) {
                resultStr=resultStr + results[i].barcodeFormatString+":"+results[i].barcodeText+'\n'
            }
            resultElement.innerHTML = (resultStr)
        } else {
            resultElement.innerHTML = "No barcode detected in this frame."
        }
        
        document.querySelector('#camera_view').appendChild(resultElement)
    })

    dce = await Dynamsoft.DCVCameraEnhancer.createInstance()
    
    dce.setScanRegion({
        regionLeft: 15,
        regionRight: 85,
        regionTop: 30,
        regionBottom: 70,
        regionMeasuredByPercentage: true
    })

   var cameraView = new Dynamsoft.DCVCameraView()

   cameraView.bindToHtmlElement(cameraViewElement)

    cameraView.setTorchButton({
        visible:true
    })

    cameraView.setOverlayVisible(true)

    dce.open()

    dbr.startScanning()
}

function onResume() {
    dce.open()
    dbr.startScanning()
}

function onPause() {
    dce.close()
    dbr.stopScanning()
}
