//
//  FaeBeautify.cpp
//  FaceppApiLib
//
//  Created by Li Cheng on 2018/9/30.
//  Copyright © 2018年 Li Cheng. All rights reserved.
//

#include "FaeBeautify.hpp"
#include "CurlPost.hpp"
#include "curl.h"

void FaceBeautyfiApi::beautify(const char *api_key,const char *api_secret,const char *file) {
    
    const char *URL = "https://api-cn.faceplusplus.com/facepp/beta/beautify";
    
    if(NULL == file) {
        fprintf(stderr, "\n\n-------请求失败-------\n %s \n\n", "file can not be empty !");
        return;
    }
    
    CurlPost curlPost = CurlPost();
    map<const char *, const char *> params;
    params.insert(map<const char *, const char *>::value_type("api_key", api_key));
    params.insert(map<const char *, const char *>::value_type("api_secret", api_secret));
    params.insert(map<const char *, const char *>::value_type("image_file", file));
    curlPost.doPost(URL, params);
}
