/*
 * =====================================================================================
 *
 *       Filename:  alg_jieba.cpp
 *
 *    Description:  cppjieba with word tag filter(include and exclude)
 *
 *        Version:  1.0
 *        Created:  02/15/2017 10:42:16 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  AngelaDoudou (Angela Meng), haotian_12@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "alg_jieba.h"

void Alg_Jieba::_init_inc_tags(const string _path){
    _inc_tags.clear();
}

void Alg_Jieba::_init_exc_tags(const string _path){
    _exc_tags.clear();
}

size_t Alg_Jieba::segment(string s, size_t topk, vector<ResultKey>& keys){
    vector<cppjieba::KeywordExtractor::Word> keywordres;
    _pjieba->extractor.Extract(s, keywordres, topk);
    for(auto& wd : keywordres){
        ResultKey rk;
        rk.key = wd.word;
        rk.wgt = wd.weight;
        keys.push_back(rk);
    }
    return keys.size();
}
