############# Live Media stuff
LIVE_MEDIA_INCLUDES = -Ilive/liveMedia/include -Ilive/BasicUsageEnvironment/include -Ilive/groupsock/include -Ilive/liveMedia/include -Ilive/UsageEnvironment/include
LIVE_MEDIA_DIRS = -Llive/liveMedia -Llive/BasicUsageEnvironment -Llive/groupsock -Llive/liveMedia -Llive/UsageEnvironment 
LIVE_MEDIA_LIBS = -lliveMedia -lBasicUsageEnvironment -lgroupsock -lliveMedia -lUsageEnvironment 

all:
	g++ main.cpp $(LIVE_MEDIA_INCLUDES) $(LIVE_MEDIA_DIRS) $(LIVE_MEDIA_LIBS) -o main
clean:
	rm -rf *.o main
