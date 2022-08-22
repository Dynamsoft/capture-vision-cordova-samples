System.register("BasicStructures", [], function (exports_1, context_1) {
    "use strict";
    var __moduleName = context_1 && context_1.id;
    return {
        setters: [],
        execute: function () {
        }
    };
});
System.register("BarcodeResult", [], function (exports_2, context_2) {
    "use strict";
    var __moduleName = context_2 && context_2.id;
    return {
        setters: [],
        execute: function () {
        }
    };
});
System.register("BarcodeSettings", [], function (exports_3, context_3) {
    "use strict";
    var EnumDBRPresetTemplate, EnumBarcodeFormat, EnumBarcodeFormat_2;
    var __moduleName = context_3 && context_3.id;
    return {
        setters: [],
        execute: function () {
            (function (EnumDBRPresetTemplate) {
                EnumDBRPresetTemplate[EnumDBRPresetTemplate["DEFAULT"] = 0] = "DEFAULT";
                EnumDBRPresetTemplate[EnumDBRPresetTemplate["VIDEO_SINGLE_BARCODE"] = 1] = "VIDEO_SINGLE_BARCODE";
                EnumDBRPresetTemplate[EnumDBRPresetTemplate["VIDEO_SPEED_FIRST"] = 2] = "VIDEO_SPEED_FIRST";
                EnumDBRPresetTemplate[EnumDBRPresetTemplate["VIDEO_READ_RATE_FIRST"] = 3] = "VIDEO_READ_RATE_FIRST";
                EnumDBRPresetTemplate[EnumDBRPresetTemplate["IMAGE_SPEED_FIRST"] = 4] = "IMAGE_SPEED_FIRST";
                EnumDBRPresetTemplate[EnumDBRPresetTemplate["IMAGE_READ_RATE_FIRST"] = 5] = "IMAGE_READ_RATE_FIRST";
                EnumDBRPresetTemplate[EnumDBRPresetTemplate["IMAGE_DEFAULT"] = 6] = "IMAGE_DEFAULT";
            })(EnumDBRPresetTemplate || (EnumDBRPresetTemplate = {}));
            exports_3("EnumDBRPresetTemplate", EnumDBRPresetTemplate);
            (function (EnumBarcodeFormat) {
                EnumBarcodeFormat[EnumBarcodeFormat["BF_ALL"] = -29360129] = "BF_ALL";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_ONED"] = 3147775] = "BF_ONED";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_GS1_DATABAR"] = 260096] = "BF_GS1_DATABAR";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_CODE_39"] = 1] = "BF_CODE_39";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_CODE_128"] = 2] = "BF_CODE_128";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_CODE_93"] = 4] = "BF_CODE_93";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_CODABAR"] = 8] = "BF_CODABAR";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_CODE_11"] = 2097152] = "BF_CODE_11";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_ITF"] = 16] = "BF_ITF";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_EAN_13"] = 32] = "BF_EAN_13";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_EAN_8"] = 64] = "BF_EAN_8";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_UPC_A"] = 128] = "BF_UPC_A";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_UPC_E"] = 256] = "BF_UPC_E";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_INDUSTRIAL_25"] = 512] = "BF_INDUSTRIAL_25";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_CODE_39_EXTENDED"] = 1024] = "BF_CODE_39_EXTENDED";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_GS1_DATABAR_OMNIDIRECTIONAL"] = 2048] = "BF_GS1_DATABAR_OMNIDIRECTIONAL";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_GS1_DATABAR_TRUNCATED"] = 4096] = "BF_GS1_DATABAR_TRUNCATED";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_GS1_DATABAR_STACKED"] = 8192] = "BF_GS1_DATABAR_STACKED";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_GS1_DATABAR_STACKED_OMNIDIRECTIONAL"] = 16384] = "BF_GS1_DATABAR_STACKED_OMNIDIRECTIONAL";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_GS1_DATABAR_EXPANDED"] = 32768] = "BF_GS1_DATABAR_EXPANDED";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_GS1_DATABAR_EXPANDED_STACKED"] = 65536] = "BF_GS1_DATABAR_EXPANDED_STACKED";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_GS1_DATABAR_LIMITED"] = 131072] = "BF_GS1_DATABAR_LIMITED";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_PATCHCODE"] = 262144] = "BF_PATCHCODE";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_PDF417"] = 33554432] = "BF_PDF417";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_QR_CODE"] = 67108864] = "BF_QR_CODE";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_DATAMATRIX"] = 134217728] = "BF_DATAMATRIX";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_AZTEC"] = 268435456] = "BF_AZTEC";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_MAXICODE"] = 536870912] = "BF_MAXICODE";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_MICRO_QR"] = 1073741824] = "BF_MICRO_QR";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_MICRO_PDF417"] = 524288] = "BF_MICRO_PDF417";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_GS1_COMPOSITE"] = -2147483648] = "BF_GS1_COMPOSITE";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_MSI_CODE"] = 1048576] = "BF_MSI_CODE";
                EnumBarcodeFormat[EnumBarcodeFormat["BF_NULL"] = 0] = "BF_NULL";
            })(EnumBarcodeFormat || (EnumBarcodeFormat = {}));
            exports_3("EnumBarcodeFormat", EnumBarcodeFormat);
            (function (EnumBarcodeFormat_2) {
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_AUSTRALIANPOST"] = 8388608] = "BF2_AUSTRALIANPOST";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_DOTCODE"] = 2] = "BF2_DOTCODE";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_NONSTANDARD_BARCODE"] = 1] = "BF2_NONSTANDARD_BARCODE";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_NULL"] = 0] = "BF2_NULL";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_PHARMACODE"] = 12] = "BF2_PHARMACODE";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_PHARMACODE_ONE_TRACK"] = 4] = "BF2_PHARMACODE_ONE_TRACK";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_PHARMACODE_TWO_TRACK"] = 8] = "BF2_PHARMACODE_TWO_TRACK";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_PLANET"] = 4194304] = "BF2_PLANET";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_POSTALCODE"] = 32505856] = "BF2_POSTALCODE";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_POSTNET"] = 2097152] = "BF2_POSTNET";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_RM4SCC"] = 16777216] = "BF2_RM4SCC";
                EnumBarcodeFormat_2[EnumBarcodeFormat_2["BF2_USPSINTELLIGENTMAIL"] = 1048576] = "BF2_USPSINTELLIGENTMAIL";
            })(EnumBarcodeFormat_2 || (EnumBarcodeFormat_2 = {}));
            exports_3("EnumBarcodeFormat_2", EnumBarcodeFormat_2);
        }
    };
});
System.register("CameraSettings", [], function (exports_4, context_4) {
    "use strict";
    var __moduleName = context_4 && context_4.id;
    return {
        setters: [],
        execute: function () {
        }
    };
});
System.register("DCVBarcodeReader", ["cordova/exec"], function (exports_5, context_5) {
    "use strict";
    var exec_1, DCVBarcodeReader;
    var __moduleName = context_5 && context_5.id;
    return {
        setters: [
            function (exec_1_1) {
                exec_1 = exec_1_1;
            }
        ],
        execute: function () {
            DCVBarcodeReader = class DCVBarcodeReader {
                constructor() {
                }
                static createInstance() {
                    let promise = new Promise(function (resolve, reject) {
                        exec_1.default(() => {
                            resolve(new DCVBarcodeReader());
                        }, (error) => {
                            reject(error);
                        }, 'DynamsoftCordovaPlugin', 'createDbrInstance', []);
                    });
                    return promise;
                }
                static initLicense(license) {
                    let promise = new Promise(function (resolve, reject) {
                        exec_1.default(() => resolve(), (error) => {
                            reject(error);
                        }, 'DynamsoftCordovaPlugin', 'initLicense', [license]);
                        console.log('after exec');
                    });
                    return promise;
                }
                static getVersion() {
                    let promise = new Promise(function (resolve, reject) {
                        exec_1.default((version) => {
                            resolve(version);
                        }, null, 'DynamsoftCordovaPlugin', 'getVersion', []);
                    });
                    return promise;
                }
                startScanning() {
                    exec_1.default(null, null, 'DynamsoftCordovaPlugin', 'startScanning', []);
                }
                stopScanning() {
                    exec_1.default(null, null, 'DynamsoftCordovaPlugin', 'stopScanning', []);
                }
                addResultListener(listener) {
                    exec_1.default(listener, null, 'DynamsoftCordovaPlugin', 'setTextResultListener', []);
                }
                getRuntimeSettings() {
                    let promise = new Promise(function (resolve, reject) {
                        exec_1.default((settings) => {
                            resolve(settings);
                        }, (error) => {
                            reject(error);
                        }, 'DynamsoftCordovaPlugin', 'getRuntimeSettings', []);
                    });
                    return promise;
                }
                outputSettingsToString() {
                    let promise = new Promise(function (resolve, reject) {
                        exec_1.default((msg) => {
                            resolve(msg);
                        }, (msg) => {
                            reject(msg);
                        }, 'DynamsoftCordovaPlugin', 'outputSettingsToString', []);
                    });
                    return promise;
                }
                updateRuntimeSettings(settings) {
                    let promise = new Promise(function (resolve, reject) {
                        exec_1.default(() => resolve(), (msg) => {
                            reject(msg);
                        }, 'DynamsoftCordovaPlugin', 'updateRuntimeSettings', [settings]);
                    });
                    return promise;
                }
                resetRuntimeSettings() {
                    exec_1.default(null, null, 'DynamsoftCordovaPlugin', 'resetRuntimeSettings', []);
                }
            };
            exports_5("DCVBarcodeReader", DCVBarcodeReader);
        }
    };
});
System.register("DCVCameraEnhancer", ["cordova/exec"], function (exports_6, context_6) {
    "use strict";
    var exec_2, EnumTorchState, DCVCameraEnhancer;
    var __moduleName = context_6 && context_6.id;
    return {
        setters: [
            function (exec_2_1) {
                exec_2 = exec_2_1;
            }
        ],
        execute: function () {
            (function (EnumTorchState) {
                EnumTorchState[EnumTorchState["OFF"] = 0] = "OFF";
                EnumTorchState[EnumTorchState["ON"] = 1] = "ON";
            })(EnumTorchState || (EnumTorchState = {}));
            DCVCameraEnhancer = class DCVCameraEnhancer {
                constructor() {
                }
                static createInstance() {
                    let promise = new Promise(function (resolve, reject) {
                        exec_2.default(() => {
                            resolve(new DCVCameraEnhancer());
                        }, null, 'DynamsoftCordovaPlugin', 'createDceInstance', []);
                    });
                    return promise;
                }
                open() {
                    let promise = new Promise(function (resolve, reject) {
                        exec_2.default(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'open', []);
                    });
                    return promise;
                }
                close() {
                    let promise = new Promise(function (resolve, reject) {
                        exec_2.default(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'close', []);
                    });
                    return promise;
                }
                turnOnTorch() {
                    let promise = new Promise(function (resolve, reject) {
                        exec_2.default(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [EnumTorchState.ON]);
                    });
                    return promise;
                }
                turnOffTorch() {
                    let promise = new Promise(function (resolve, reject) {
                        exec_2.default(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'setTorchState', [EnumTorchState.OFF]);
                    });
                    return promise;
                }
                setScanRegion(region) {
                    if (region) {
                        region.regionMeasuredByPercentage = region.regionMeasuredByPercentage ? 1 : 0;
                    }
                    let promise = new Promise(function (resolve, reject) {
                        exec_2.default(() => resolve(), (error) => reject(error), 'DynamsoftCordovaPlugin', 'setScanRegion', [region]);
                    });
                    return promise;
                }
                setScanRegionVisible(isVisible) {
                    exec_2.default(null, null, 'DynamsoftCordovaPlugin', 'setScanRegionVisible', [isVisible]);
                }
            };
            exports_6("DCVCameraEnhancer", DCVCameraEnhancer);
        }
    };
});
System.register("DCVCameraView", ["cordova/exec"], function (exports_7, context_7) {
    "use strict";
    var exec_3, HTMLElementProp, DCVCameraView;
    var __moduleName = context_7 && context_7.id;
    return {
        setters: [
            function (exec_3_1) {
                exec_3 = exec_3_1;
            }
        ],
        execute: function () {
            HTMLElementProp = class HTMLElementProp {
                constructor() {
                    this.isVisible = false;
                    this.position = null;
                    this.underWebView = false;
                }
                isValid() {
                    return this.isVisible !== undefined && this.isVisible !== null
                        && this.position !== undefined && this.position !== null
                        && this.underWebView !== undefined && this.underWebView !== null;
                }
                didChangeComparedTo(other) {
                    if (this.position == null || other == null || other.position == null) {
                        return false;
                    }
                    else {
                        return this.position.x !== other.position.x || this.position.y !== other.position.y || this.position.width !== other.position.width || this.position.height !== other.position.height
                            || this.underWebView !== other.underWebView;
                    }
                }
            };
            DCVCameraView = class DCVCameraView {
                constructor() {
                    this.elementObserver = new MutationObserver(this.elementDidChange.bind(this));
                    this.htmlElement = null;
                    this.htmlElementProp = new HTMLElementProp();
                    this._htmlElementProp = new HTMLElementProp();
                    this.scrollListener = this.elementDidChange.bind(this);
                    this.orientationListener = (() => {
                        this.elementDidChange();
                        setTimeout(this.elementDidChange.bind(this), 100);
                        setTimeout(this.elementDidChange.bind(this), 300);
                        setTimeout(this.elementDidChange.bind(this), 1000);
                    });
                }
                bindToHtmlElement(element) {
                    this.htmlElement = element;
                    this.elementDidChange();
                    this.setElementChangeListener();
                    exec_3.default(null, null, 'DynamsoftCordovaPlugin', 'bindCameraViewToElement', [this.htmlElementProp]);
                }
                setOverlayVisible(isVisible) {
                    exec_3.default(null, null, 'DynamsoftCordovaPlugin', 'setOverlayVisible', [isVisible]);
                }
                setTorchButton(torchButton) {
                    exec_3.default(null, null, 'DynamsoftCordovaPlugin', 'setTorchButton', [torchButton]);
                }
                set htmlElementProp(newProp) {
                    var didChangeShown;
                    var didChangePositionOrSize;
                    if (this._htmlElementProp) {
                        didChangeShown = this._htmlElementProp.isVisible !== newProp.isVisible;
                        didChangePositionOrSize = this._htmlElementProp.didChangeComparedTo(newProp);
                    }
                    else {
                        didChangeShown = true;
                        didChangePositionOrSize = true;
                    }
                    this._htmlElementProp = newProp;
                    if (didChangePositionOrSize) {
                        this.updateCameraViewPosition();
                    }
                    if (didChangeShown && this.htmlElementProp) {
                        if (this.htmlElementProp.isVisible) {
                            this.setCameraViewVisible(true);
                        }
                        else {
                            this.setCameraViewVisible(false);
                        }
                    }
                }
                get htmlElementProp() {
                    return this._htmlElementProp;
                }
                updateCameraViewPosition() {
                    if (!this.htmlElementProp || !this.htmlElementProp.isValid) {
                        return;
                    }
                    exec_3.default(null, null, 'DynamsoftCordovaPlugin', 'updateCameraViewPosition', [this.htmlElementProp.position]);
                }
                setCameraViewVisible(isVisible) {
                    exec_3.default(null, null, 'DynamsoftCordovaPlugin', 'setCameraViewVisible', [isVisible]);
                }
                elementDidChange() {
                    if (!this.htmlElement) {
                        this.htmlElementProp = new HTMLElementProp();
                        return;
                    }
                    const newProp = new HTMLElementProp();
                    const boundingRect = this.htmlElement.getBoundingClientRect();
                    newProp.position = { x: boundingRect.x - visualViewport.offsetLeft, y: boundingRect.y - visualViewport.offsetTop, width: boundingRect.width, height: boundingRect.height };
                    newProp.underWebView = parseInt(this.htmlElement.style.zIndex || '1', 10) < 0
                        || parseInt(getComputedStyle(this.htmlElement).zIndex || '1', 10) < 0;
                    const isDisplayed = getComputedStyle(this.htmlElement).display !== 'none'
                        && this.htmlElement.style.display !== 'none';
                    const isInDOM = document.body.contains(this.htmlElement);
                    newProp.isVisible = isDisplayed && isInDOM && !this.htmlElement.hidden;
                    this.htmlElementProp = newProp;
                }
                setElementChangeListener() {
                    this.elementObserver.observe(document, { attributes: true, childList: true, subtree: true });
                    visualViewport.addEventListener('scroll', this.scrollListener);
                    window.addEventListener('orientationchange', this.orientationListener);
                }
            };
            exports_7("DCVCameraView", DCVCameraView);
        }
    };
});
