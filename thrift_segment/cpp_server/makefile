segmentsr:segmentserver.cpp alg_jieba.cpp gen-cpp/ArticleService.cpp gen-cpp/segment_constants.cpp gen-cpp/segment_types.cpp
	g++ -std=c++11 -g -DHAVE_NETINET_IN_H -I. -I/usr/local/include/thrift -Icppjieba/deps -L/usr/local/lib -o segmentsr segmentserver.cpp alg_jieba.cpp gen-cpp/ArticleService.cpp gen-cpp/segment_constants.cpp gen-cpp/segment_types.cpp -lthriftnb -levent -lthrift -lrt
clean:
	rm segmentsr


