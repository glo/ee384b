#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"

UsageEnvironment* env;

// To make the second and subsequent client for each stream reuse the same
// input stream as the first client (rather than playing the file from the
// start for each client), change the following "False" to "True":
Boolean reuseFirstSource = False;

// To stream *only* MPEG-1 or 2 video "I" frames
// (e.g., to reduce network bandwidth),
// change the following "False" to "True":
Boolean iFramesOnly = False;

static void announceStream(RTSPServer* rtspServer, ServerMediaSession* sms, char const* streamName, char const* inputFileName); // fwd

int main(int argc, char** argv) {
	// Begin by setting up our usage environment:
	TaskScheduler* scheduler = BasicTaskScheduler::createNew();
	env = BasicUsageEnvironment::createNew(*scheduler);

	// Create the RTSP server:
	RTSPServer* rtspServer = RTSPServer::createNew(*env, 8554, NULL);
	if (rtspServer == NULL) {
		*env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
		exit(1);
	}

	char const* descriptionString = "Session streamed by \"Gloria's RTSP Server\"";
	
	// A MPEG-4 video elementary stream:
	char const* streamName = "mpeg4ESVideo";
	char const* inputFileName = "test.m4e";
	ServerMediaSession* sms = ServerMediaSession::createNew(*env, streamName, streamName, descriptionString);
	sms->addSubsession(MPEG4VideoFileServerMediaSubsession::createNew(*env, inputFileName, reuseFirstSource));
	rtspServer->addServerMediaSession(sms);
	
	announceStream(rtspServer, sms, streamName, inputFileName);
	
	env->taskScheduler().doEventLoop(); // does not return
}


static void announceStream(RTSPServer* rtspServer, ServerMediaSession* sms, char const* streamName, char const* inputFileName) {
char* url = rtspServer->rtspURL(sms);
	UsageEnvironment& env = rtspServer->envir();
	env << "\n\"" << streamName << "\" stream, from the file \"" << inputFileName << "\"\n";
	env << "Play this stream using the URL \"" << url << "\"\n";
	delete[] url;
}
