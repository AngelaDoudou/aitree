/*
 * =====================================================================================
 *
 *       Filename:  alg_jieba.h
 *
 *    Description:  cppjieba with word tag filter(include and exclude) 
 *
 *        Version:  1.0
 *        Created:  02/15/2017 11:28:21 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  AngelaDoudou (Angela Meng), haotian_12@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <set>
#include "cppjieba/include/cppjieba/Jieba.hpp"
//#include "util/conf_reader.h"

using namespace std;

const char* const DICT_PATH = "../cppjieba/dict/jieba.dict.utf8";
const char* const HMM_PATH = "../cppjieba/dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "../cppjieba/dict/user.dict.utf8";
const char* const IDF_PATH = "../cppjieba/dict/idf.utf8";
const char* const STOP_WORD_PATH = "../cppjieba/dict/stop_words.utf8";

class Alg_Jieba{
    private:
        cppjieba::Jieba* _pjieba;
        set<string> _inc_tags;
        set<string> _exc_tags;

        void _init_inc_tags(const string _path);
        void _init_exc_tags(const string _path);

    public:
        struct ResultKey{
            string key;
            double wgt;
        };
        Alg_Jieba(){      
            _pjieba = new cppjieba::Jieba(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH);
        }
        ~Alg_Jieba(){
            delete _pjieba;
        }
        /*Alg_Jieba(const Configure _conf): _jieba(_conf["dict_path"], 
                                                 _conf["hmm_path"], 
                                                 _conf["user_dict_path"], 
                                                 _conf["idf_path"],
                                                 _conf["stop_word_path"]){
            _init_inc_tags(_conf["include_tags_path"]);
            _init_exc_tags(_conf["exclude_tags_path"]);
        }*/
        size_t segment(string s, size_t topk, vector<ResultKey>& keys);
};
