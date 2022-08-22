import { TorchButton } from './CameraSettings';
export declare class DCVCameraView {
    private htmlElement;
    private _htmlElementProp;
    private scrollListener;
    private orientationListener;
    private elementObserver;
    private iosMainVersion;
    constructor();
    bindToHtmlElement(element: HTMLElement): void;
    setOverlayVisible(isVisible: boolean): void;
    setTorchButton(torchButton: TorchButton): void;
    private set htmlElementProp(value);
    private get htmlElementProp();
    private updateCameraViewPosition;
    private setCameraViewVisible;
    private elementDidChange;
    private setElementChangeListener;
}
