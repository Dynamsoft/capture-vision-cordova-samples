"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.DCVCameraView = void 0;
const exec_1 = __importDefault(require("cordova/exec"));
class HTMLElementProp {
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
}
class DCVCameraView {
    constructor() {
        this.elementObserver = new MutationObserver(this.elementDidChange.bind(this));
        this.htmlElement = null;
        this.htmlElementProp = new HTMLElementProp();
        this._htmlElementProp = new HTMLElementProp();
        this.scrollListener = this.elementDidChange.bind(this);
        this.iosMainVersion = null;
        let ver = navigator.userAgent.toLowerCase().match(/cpu iphone os (.*?) like mac os/);
        if (ver != null && ver[1] != null && ver[1] != undefined) {
            let str = ver[1].split('_')[0];
            if (str != null && str != undefined) {
                this.iosMainVersion = Number(str);
            }
        }
        this.orientationListener = (() => {
            this.elementDidChange();
            setTimeout(this.elementDidChange.bind(this), 100);
            setTimeout(this.elementDidChange.bind(this), 300);
            setTimeout(this.elementDidChange.bind(this), 1000);
        });
        this.createDceView();
    }
    createDceView() {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'createDceView', null);
    }
    /**
    * Bind the instance of DCVCameraView to an HTML element.
    */
    bindToHtmlElement(element) {
        this.htmlElement = element;
        this.elementDidChange();
        this.setElementChangeListener();
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'bindCameraViewToElement', [this.htmlElementProp]);
    }
    /**
    * Set whether to display overlays to highlight the decoded barcodes.
    */
    setOverlayVisible(isVisible) {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'setOverlayVisible', [isVisible]);
    }
    /**
    * Set the torch button with a TorchButton object.
    * You can configure the position, images and visibility of the button.
    */
    setTorchButton(torchButton) {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'setTorchButton', [torchButton]);
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
        if (!this.htmlElementProp || !this.htmlElementProp.isValid()) {
            return;
        }
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'updateCameraViewPosition', [this.htmlElementProp.position]);
    }
    setCameraViewVisible(isVisible) {
        (0, exec_1.default)(null, null, 'DynamsoftCordovaPlugin', 'setCameraViewVisible', [isVisible]);
    }
    elementDidChange() {
        if (!this.htmlElement) {
            this.htmlElementProp = new HTMLElementProp();
            return;
        }
        const newProp = new HTMLElementProp();
        const boundingRect = this.htmlElement.getBoundingClientRect();
        if (this.iosMainVersion && this.iosMainVersion < 13) {
            newProp.position = { x: boundingRect.x, y: boundingRect.y, width: boundingRect.width, height: boundingRect.height };
        }
        else {
            newProp.position = { x: boundingRect.x - visualViewport.offsetLeft, y: boundingRect.y - visualViewport.offsetTop, width: boundingRect.width, height: boundingRect.height };
        }
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
        if (this.iosMainVersion && this.iosMainVersion < 13) {
            window.addEventListener('scroll', this.scrollListener);
        }
        else {
            visualViewport.addEventListener('scroll', this.scrollListener);
        }
        window.addEventListener('orientationchange', this.orientationListener);
    }
}
exports.DCVCameraView = DCVCameraView;
