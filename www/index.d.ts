declare module Dynamsoft {
    export interface Quadrilateral {
        /**
        * Vertex coordinates of the quadrilateral.
        */
        points: Point[];
    }
    export interface Point {
        /**
        * X coordinate of the point.
        */
        x: number;
        /**
        * Y coordinate of the point.
        */
        y: number;
    }
    export interface Region {
        /**
        * Y coordinate of the buttom border of the region.
        */
        regionBottom: number;
        /**
        * X coordinate of the right border of the region.
        */
        regionRight: number;
        /**
        * X coordinate of the left border of the region.
        */
        regionLeft: number;
        /**
        * Y coordinate of the top border of the region.
        */
        regionTop: number;
        /**
        * 1/True: the coordinates are measured by percentage.
        * 0/False: the coordinates are measured by pixel distance.
        */
        regionMeasuredByPercentage: number | boolean;
    }
    export interface Rect {
        /**
        * X coordinate of the top-left vertex of the rectangle.
        */
        x: number;
        /**
        * Y coordinate of the top-left vertex of the rectangle.
        */
        y: number;
        /**
        * The width of the rectangle.
        */
        width: number;
        /**
        * The height of the rectangle.
        */
        height: number;
    }
    export interface BarcodeResult {
        /**
        * The barcode text.
        */
        barcodeText: string;
        /** 
        * The byte of barcodeText. 
        */ 
        barcodeBytes: string; 
        /**
        * Barcode type in string.
        */
        barcodeFormatString: string;
        /**
        * The corresponding localization result.
        */
        barcodeLocation: BarcodeLocationResult;
    }
    export interface BarcodeLocationResult {
        /**
         * The angle of a barcode. Values range from 0 to 360.
         */
        angle: number;
        /**
         * The quadrilateral
         */
        quadrilateral: Quadrilateral;
    }
    export interface DBRRuntimeSettings {
        /**
        * A combined value of EnumBarcodeFormat members.
        */
        barcodeFormatIds: number;
        /**
        * A combined value of EnumBarcodeFormat_2 members.
        */
        barcodeFormatIds_2: number;
        /**
        * Defines how many barcodes you want decode from a single image.
        */
        expectedBarcodesCount: number;
        /**
        * Defines the maximum time consumption on processing a single image.
        */
        timeout: number;
    }
    export enum EnumDBRPresetTemplate {
        /**
        * The default setting for processing the video streaming.
        */
        DEFAULT = 0,
        /**
        * Use this template when processing single barcode under the video streaming.
        */
        VIDEO_SINGLE_BARCODE = 1,
        /**
        * Use this template for higher speed when processing the video streaming.
        */
        VIDEO_SPEED_FIRST = 2,
        /**
        * Use this template for higher read rate when processing the video streaming.
        */
        VIDEO_READ_RATE_FIRST = 3,
        /**
        * Use this template for higher speed when processing a still image.
        */
        IMAGE_SPEED_FIRST = 4,
        /**
        * Use this template for higher read rate when processing a still image.
        */
        IMAGE_READ_RATE_FIRST = 5,
        /**
        * The default setting for processing a still image.
        */
        IMAGE_DEFAULT = 6
    }
    /**
    * The first group of barcode formats.
    */
    export enum EnumBarcodeFormat {
        BF_ALL = -29360129,
        BF_ONED = 3147775,
        BF_GS1_DATABAR = 260096,
        BF_CODE_39 = 1,
        BF_CODE_128 = 2,
        BF_CODE_93 = 4,
        BF_CODABAR = 8,
        BF_CODE_11 = 2097152,
        BF_ITF = 16,
        BF_EAN_13 = 32,
        BF_EAN_8 = 64,
        BF_UPC_A = 128,
        BF_UPC_E = 256,
        BF_INDUSTRIAL_25 = 512,
        BF_CODE_39_EXTENDED = 1024,
        BF_GS1_DATABAR_OMNIDIRECTIONAL = 2048,
        BF_GS1_DATABAR_TRUNCATED = 4096,
        BF_GS1_DATABAR_STACKED = 8192,
        BF_GS1_DATABAR_STACKED_OMNIDIRECTIONAL = 16384,
        BF_GS1_DATABAR_EXPANDED = 32768,
        BF_GS1_DATABAR_EXPANDED_STACKED = 65536,
        BF_GS1_DATABAR_LIMITED = 131072,
        BF_PATCHCODE = 262144,
        BF_PDF417 = 33554432,
        BF_QR_CODE = 67108864,
        BF_DATAMATRIX = 134217728,
        BF_AZTEC = 268435456,
        BF_MAXICODE = 536870912,
        BF_MICRO_QR = 1073741824,
        BF_MICRO_PDF417 = 524288,
        BF_GS1_COMPOSITE = -2147483648,
        BF_MSI_CODE = 1048576,
        BF_NULL = 0
    }

    /**
    * The second group of barcode formats.
    */
    export enum EnumBarcodeFormat_2 {
        BF2_AUSTRALIANPOST = 8388608,
        BF2_DOTCODE = 2,
        BF2_NONSTANDARD_BARCODE = 1,
        BF2_NULL = 0,
        BF2_PHARMACODE = 12,
        BF2_PHARMACODE_ONE_TRACK = 4,
        BF2_PHARMACODE_TWO_TRACK = 8,
        BF2_PLANET = 4194304,
        BF2_POSTALCODE = 32505856,
        BF2_POSTNET = 2097152,
        BF2_RM4SCC = 16777216,
        BF2_USPSINTELLIGENTMAIL = 1048576
    }
    export interface TorchButton {
        /**
        * Defines the location of the torch button.
        */
        location: Rect;
        /**
        * True: the torch will be displayed.
        * False: the torch will be hide.
        */
        visible: boolean;
        /**
        * A base 64 string that specify the torch on image.
        * When the torch is on, this image will be displayed as the torch image.
        */
        torchOnImage: string;
        /**
        * A base 64 string that specify the torch off image.
        * When the torch is off, this image will be displayed as the torch image.
        */
        torchOffImage: string;
    }
    export class DCVBarcodeReader {
        private constructor();

        /**
        * Create an instance of the DCVBarcode reader.
        */
        static createInstance(): Promise<DCVBarcodeReader>;
        
        /**
        * Initialize the license with a license key.
        */
        static initLicense(license: String): Promise<void>;

        /**
        * Get the version of the barcode reader library.
        */
        static getVersion(): Promise<String>;

        /**
        * Start barcode decoding from the video streaming.
        */
        startScanning(): void;
        
        /**
        * Stop barcode decoding from the video streaming.
        */
        stopScanning(): void;

        /**
        * Register a listener to receive callback when barcode result is output.
        */
        addResultListener(listener: (results: BarcodeResult[]) => void): void;

        /**
        * Get the current runtime settings as a DBRRuntimeSettings object.
        */
        getRuntimeSettings(): Promise<DBRRuntimeSettings>;

        /**
        * Output the current runtime settings as a string.
        */
        outputSettingsToString(): Promise<String>;

        /**
        * Update the current runtime settings with a DBRRuntimeSettings object / a preset template / a JSON string.
        */
        updateRuntimeSettings(settings: String | DBRRuntimeSettings | EnumDBRPresetTemplate): Promise<void>;

        /**
        * Reset the runtime settings.
        */
        resetRuntimeSettings(): void;
    }
    export class DCVCameraEnhancer {
        private constructor();
        static createInstance(): Promise<DCVCameraEnhancer>;
        /**
        * Open the camera.
        */
        open(): Promise<void>;
        /**
        * CLose the camera.
        */
        close(): Promise<void>;
        /**
        * Turn on the torch.
        */
        turnOnTorch(): Promise<void>;
        /**
        * Turn off the torch.
        */
        turnOffTorch(): Promise<void>;
        /**
        * Specify a region of interest with a region object.
        */
        setScanRegion(region: Region): Promise<void>;
        /**
        * Set whether to display the scan region.
        */
        setScanRegionVisible(isVisible: boolean): void;
    }
    export class DCVCameraView {
        private htmlElement;
        private _htmlElementProp;
        private scrollListener;
        private orientationListener;
        private elementObserver;
        constructor();
        /**
        * Bind the instance of DCVCameraView to an HTML element.
        */
        bindToHtmlElement(element: HTMLElement): void;
        /**
        * Set whether to display overlays to highlight the decoded barcodes.
        */
        setOverlayVisible(isVisible: boolean): void;
        /**
        * Set the torch button with a TorchButton object.
        * You can configure the position, images and visibility of the button.
        */
        setTorchButton(torchButton: TorchButton): void;
        private set htmlElementProp(value);
        private get htmlElementProp();
        private updateCameraViewPosition;
        private setCameraViewVisible;
        private elementDidChange;
        private setElementChangeListener;
    }
}
