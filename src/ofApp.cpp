#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){

 	FC2Version fc2Version;
    	//Utilities::GetLibraryVersion( &fc2Version );
    
	ostringstream version;
	version << "FlyCapture2 library version: " << fc2Version.major << "." << fc2Version.minor << "." << fc2Version.type << "." << fc2Version.build;
	cout << version.str() << endl;  
    
	ostringstream timeStamp;
    timeStamp <<"Application build date: " << __DATE__ << " " << __TIME__;
	cout << timeStamp.str() << endl << endl;  
		
	 BusManager busMgr;
    unsigned int numCameras;
    error = busMgr.GetNumOfCameras(&numCameras);
    if (error != PGRERROR_OK)
    {
        PrintError( error );
        
    }
	
 	PGRGuid guid;
    cout << "Number of cameras detected: " << numCameras << endl; 

    for (unsigned int i=0; i < numCameras; i++)
    {
       
        error = busMgr.GetCameraFromIndex(i, &guid);
        if (error != PGRERROR_OK)
        {
            PrintError( error );
           
        }

       // RunSingleCamera( guid );
    }
	
    error = cam.Connect(&guid);
    if (error != PGRERROR_OK)
    {
        PrintError( error );
       
    }

    CameraInfo camInfo;
    error = cam.GetCameraInfo(&camInfo);
    if (error != PGRERROR_OK)
    {
        PrintError( error );
       
    }

 	error = cam.StartCapture();
    if (error != PGRERROR_OK)
    {
        PrintError( error );
        
    

	}
	error = cam.StopCapture();

	error = cam.StartCapture();

	
}

//--------------------------------------------------------------
void ofApp::update(){

	 error = cam.RetrieveBuffer( &rawImage );
        if (error != PGRERROR_OK)
        {
            PrintError( error );
        }
	grayImage.setFromPixels(rawImage.GetData(), 808, 608, OF_IMAGE_GRAYSCALE);

}

//--------------------------------------------------------------
void ofApp::draw(){
	grayImage.draw(0,0);
}

void ofApp::exit(){
 // Stop capturing images
    error = cam.StopCapture();
    if (error != PGRERROR_OK)
    {
        PrintError( error );
        
    }      

    // Disconnect the camera
    error = cam.Disconnect();
    if (error != PGRERROR_OK)
    {
        PrintError( error );
       
    }
}

void ofApp::PrintError (Error error){
    error.PrintErrorTrace();
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
