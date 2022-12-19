import { Rect } from "./BasicStructures";

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
    * The file path of the torch on image.
    * When the torch is on, this image will be displayed as the torch image.
    */
    torchOnImage: string;
    /**
    * The file path of the torch off image.
    * When the torch is off, this image will be displayed as the torch image.
    */
    torchOffImage: string;
}