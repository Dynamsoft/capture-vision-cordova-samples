"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.DCVBarcodeReader = void 0;
const exec_1 = __importDefault(require("cordova/exec"));
class DCVBarcodeReader {
    constructor() {
    }
    /**
    * Create an instance of the DCVBarcode reader.
    */
    static createInstance() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => {
                resolve(new DCVBarcodeReader());
            }, (error) => {
                reject(error);
            }, 'DynamsoftCordovaPlugin', 'createDbrInstance', []);
        });
        return promise;
    }
    /**
    * Initialize the license with a license key.
    */
    static initLicense(license) {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => {
                reject(error);
            }, 'DynamsoftCordovaPlugin', 'initLicense', [license]);
        });
        return promise;
    }
    /**
    * Get the version of the barcode reader library.
    */
    static getVersion() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)((version) => {
                resolve(version);
            }, null, 'DynamsoftCordovaPlugin', 'getVersion', []);
        });
        return promise;
    }
    /**
    * Start barcode decoding from the video streaming.
    */
    startScanning() {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'startScanning', []);
    }
    /**
    * Stop barcode decoding from the video streaming.
    */
    stopScanning() {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'stopScanning', []);
    }
    /**
    * Register a listener to receive callback when barcode result is output.
    */
    addResultListener(listener) {
        (0, exec_1.default)(listener, null, 'DynamsoftCordovaPlugin', 'setTextResultListener', []);
    }
    /**
    * Get the current runtime settings as a DBRRuntimeSettings object.
    */
    getRuntimeSettings() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)((settings) => {
                resolve(settings);
            }, (error) => {
                reject(error);
            }, 'DynamsoftCordovaPlugin', 'getRuntimeSettings', []);
        });
        return promise;
    }
    /**
    * Output the current runtime settings as a string.
    */
    outputSettingsToString() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)((msg) => {
                resolve(msg);
            }, (msg) => {
                reject(msg);
            }, 'DynamsoftCordovaPlugin', 'outputSettingsToString', []);
        });
        return promise;
    }
    /**
    * Update the current runtime settings with a DBRRuntimeSettings object / a preset template / a JSON string.
    */
    updateRuntimeSettings(settings) {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (msg) => {
                reject(msg);
            }, 'DynamsoftCordovaPlugin', 'updateRuntimeSettings', [settings]);
        });
        return promise;
    }
    /**
    * Reset the runtime settings.
    */
    resetRuntimeSettings() {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'resetRuntimeSettings', []);
    }
}
exports.DCVBarcodeReader = DCVBarcodeReader;
