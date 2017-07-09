/*
 * =====================================================================================
 *
 *       Filename:  demo.cpp
 *
 *    Description:  test alg_jieba class
 *
 *        Version:  1.0
 *        Created:  02/15/2017 03:16:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  AngelaDoudou (Angela Meng), haotian_12@163.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <vector>
#include <iostream>
#include "alg_jieba.h"
using namespace std;
int main(int argc, char** argv){

    Alg_Jieba jieba;
    
    vector<Alg_Jieba::ResultKey> keys;

    jieba.segment("我是拖拉机学院手扶拖拉机专业的。不用多久，我就会升职加薪，当上CEO，走上人生巅峰。", 5, keys);
    
    int i = 0;
    for(auto & k:keys){
        cout << "key[" << i++ << "]=<" << k.key << "," << k.wgt << ">" << endl;
    }
    return 0;
}

