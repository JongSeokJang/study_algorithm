#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    
    int totalTime = 0;
    int ii, jj, kk;
    int searchFlag = 0;
    int searchIndex = 0;
    vector<string> cache;
    
    for( ii = 0; ii < cities.size(); ii++){
        
        searchFlag = 0;
        searchIndex = 0;
        
        for( jj = 0; jj < cache.size(); jj++){
            
            for( kk = 0; kk < cities[ii].length(); kk++){
                if(  'A'<= cities[ii][kk] && cities[ii][kk] <= 'Z')
                    cities[ii][kk] = cities[ii][kk] -'A' + 'a';
            }
           if( cities[ii] == cache[jj] ) {
               searchFlag = 1;
               searchIndex = jj;
               break;
           }
        }
        if( searchFlag ){
            for( jj = searchIndex; jj < cache.size()-1; jj++)
                cache[jj] = cache[jj+1];
            cache.pop_back();
            
            for( jj = 0; jj < cities[ii].length(); jj++){
                if( 'A' <= cities[ii][jj]  && cities[ii][jj] <= 'Z')
                    cities[ii][jj] = cities[ii][jj] - 'A' + 'a';
            }
            cache.push_back(cities[ii]);
            totalTime += 1;
        }
        else{
            if( cache.size() == cacheSize ){
                
                if( cacheSize == 0){
                    
                }
                else{
                    for( jj = 0; jj < cache.size()-1; jj++ )
                        cache[jj] = cache[jj+1];
                    cache.pop_back();

                    for( jj = 0; jj < cities[ii].length(); jj++){
                        if( 'A' <= cities[ii][jj]  && cities[ii][jj] <= 'Z')
                            cities[ii][jj] = cities[ii][jj] - 'A' + 'a';
                    }
                    cache.push_back(cities[ii]);
                }
            }
            else{
                for( jj = 0; jj < cities[ii].length(); jj++){
                    if( 'A' <= cities[ii][jj]  && cities[ii][jj] <= 'Z')
                        cities[ii][jj] = cities[ii][jj] - 'A' + 'a';
                }
                cache.push_back(cities[ii]);
            }
            totalTime += 5;
        }
        
    }
    return totalTime;
    //return answer;
}
