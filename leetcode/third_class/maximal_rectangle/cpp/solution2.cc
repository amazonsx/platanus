#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sys/time.h>
using namespace std;
class Solution {
    public:
        int maximalRectangle(vector<vector<char> > &matrix) {
            int height = matrix.size();
            if (height == 0)    return 0;
            int width = matrix[0].size();
            if (width == 0) return 0;
            vector<vector<vector<int> > > rowRect(height, vector<vector<int> >() );
            vector<vector<vector<int> > > colRect(width, vector<vector<int> >() );
            for ( int i = 0; i < (signed)height; i ++) {
                int j = 0; 
                while (j != width) {
                    if (matrix[i][j] == '1') {
                        int len = 0;
                        while(j < width && matrix[i][j] == '1') {
                            len ++;
                            j ++;
                        }
                        rowRect[i].push_back(vector<int>(1,j-len));
                        rowRect[i].back().push_back(--j);    
                    }
                    j ++;
                }
            }
            for ( int i = 0; i < (signed)width; i ++) {
                int j = 0;
                while ( j != height) {
                    if (matrix[j][i] == '1') {
                        int len = 0;
                        while ( j < height && matrix[j][i] == '1') {
                            len ++;
                            j ++;
                        }
                        colRect[i].push_back(vector<int>(1,j-len));
                        colRect[i].back().push_back(--j);
                    }
                    j ++;
                }
            }
            int maxarea = 0;
            for ( int i = 0; i < (signed)height; i ++) {
                for ( int j = 0; j <rowRect[i].size(); j ++) {
                    int start = rowRect[i][j][0];
                    int end = rowRect[i][j][1];
                    for ( int k = start; k <= end; k ++ ) {
                        int minHeight = height;
                        for ( int m = k; m <= end; m ++) {
                            int tmparea = 0;
                            for ( int n = 0; n < colRect[m].size(); n ++) {
                                if ( colRect[m][n][0] <= i && colRect[m][n][1] >= i) {
                                    minHeight = min(minHeight, colRect[m][n][1]-i+1);
                                    tmparea = max(tmparea, minHeight*(m-k+1));
                                }
                            }
                            maxarea = max(maxarea, tmparea);
                        }
                    }
                }
            }
            return maxarea;
        }
};

int main(int argc, char *argv[]) {
    Solution s;
    vector<vector<char> > matrix;
    //string strs[] = {"0010", "1111", "1111", "1110", "1100", "1111", "1110"};
    string strs[] = {"1111111111111101001111111100111011111111","1111011011111111101101111101111111111111","0111101011111101101101101111111111111111","0101101011111111111101111111010110111111","1111111111110111110110010111111111111111","1111111110110101111111111101011111101111","0110110101110011111111111111110111110101","0111111111111100111111100110011011010101","1111011110111111111011011011110101101011","1111111110111111111101101101110111101111","1110110011111111111100111111111111111111","1011111110111101111001110111111111111111","0110111111111111101111110111011111011111","1111111111111111011111111111110111111011","1111100111111110101100111111111111101111","1111101111111110111111011111111111011111","1111101111111111111111011001111110011111","1111110111111111011111111111110111110111","1011111111111111010111110010111110111111","1111110011111111111110111111111111111011","1111111111111111110111011111011111011011","1100011011111111111111011111011111111111","1111101011111111111101100101110011111111","1110010111111111111011011110111101111101","1111111111111101101111111111101111111111","1111111011111101111011111111111110111111","1110011111111110111011111111110111110111","1111111111111100111111010111111111110111","1111111111111111111111000111111111011101","1111110111111111111111111101100111011011","1111011011111101101101111110111111101111","1111111111011111111111111111111111111111","1111111111111111111111111111111111111111","1100011111111110111111111111101111111011","1111101111111101111010111111111111111111","0111111111110011111111110101011011111111","1011011111101111111111101111111111110011","1010111111111111111111111111111110011111","0111101111011111111111111111110111111111","0111111011111111011101111011101111111111","0111111111110101111011111101011001111011","1111111111111011110111111101111111101110","1111101111111100111111111110111111001111","1101101111110101111101111111100111010100","0110111111100111110010111110111011011101"};
    for ( int i = 0; i < sizeof(strs)/sizeof(string); i ++) {
        vector<char> tmp;
        for ( int j = 0; j < strs[i].size(); j ++) {
            tmp.push_back(strs[i][j]);
        }
        matrix.push_back(tmp);
    }
    cout << s.maximalRectangle(matrix) << endl;
}
