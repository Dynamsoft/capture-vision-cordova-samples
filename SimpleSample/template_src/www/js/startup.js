document.addEventListener('deviceready', onDeviceReady, false)

function onDeviceReady() { 
    console.log('Running cordova-' + cordova.platformId + '@' + cordova.version);
    document.getElementById('deviceready').classList.add('ready');
    const btnStartScanning = document.getElementById("btn_start_scanning")
    btnStartScanning.onclick = () => {
        window.location.href = 'scanPage.html'
    }
}