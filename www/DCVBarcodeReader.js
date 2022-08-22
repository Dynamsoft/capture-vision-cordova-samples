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
    static initLicense(license) {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (error) => {
                reject(error);
            }, 'DynamsoftCordovaPlugin', 'initLicense', [license]);
        });
        return promise;
    }
    static getVersion() {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)((version) => {
                resolve(version);
            }, null, 'DynamsoftCordovaPlugin', 'getVersion', []);
        });
        return promise;
    }
    startScanning() {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'startScanning', []);
    }
    stopScanning() {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'stopScanning', []);
    }
    addResultListener(listener) {
        (0, exec_1.default)(listener, null, 'DynamsoftCordovaPlugin', 'setTextResultListener', []);
    }
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
    updateRuntimeSettings(settings) {
        let promise = new Promise(function (resolve, reject) {
            (0, exec_1.default)(() => resolve(), (msg) => {
                reject(msg);
            }, 'DynamsoftCordovaPlugin', 'updateRuntimeSettings', [settings]);
        });
        return promise;
    }
    resetRuntimeSettings() {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'resetRuntimeSettings', []);
    }
}
exports.DCVBarcodeReader = DCVBarcodeReader;
