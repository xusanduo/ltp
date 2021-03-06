#ifndef __LTP_POSTAGGER_DLL_H__
#define __LTP_POSTAG_DLL_H__

#include <iostream>
#include <vector>

#define POSTAGGER_DLL_API
#define POSTAGGER_DLL_API_EXPORT

#ifdef _WIN32
#undef POSTAGGER_DLL_API
#ifdef POSTAGGER_DLL_API_EXPORT
    #define POSTAGGER_DLL_API extern "C" _declspec(dllexport)
#else
    #define POSTAGGER_DLL_API extern "C" _deslspec(dllimport)
    #pragma comment(lib, "postagger.lib")
#endif // end for PARSER_DLL_API
#endif // end for _WIN32

/*
 * create a new postagger
 *
 *  @param[in] path the path of the model
 *  @return void * the pointer to the segmentor
 */
POSTAGGER_DLL_API void * postagger_create_postagger(const char * path);

/*
 * release the postagger resources
 * 
 *  @param[in]  segmentor   the segmentor
 *  @return     int         i don't know
 */
POSTAGGER_DLL_API int postagger_release_postagger(void * postagger);

/*
 * run postag given the postagger on the input words
 *
 *  @param[in]  words       the string to be segmented
 *  @param[out] tags        the words of the input line
 *  @return     int         the number of word tokens
 */
POSTAGGER_DLL_API int postagger_postag(void * postagger,
        const std::vector< std::string > & words,
        std::vector<std::string> & tags);

#endif  //  end for __LTP_POSTAG_DLL_H__
