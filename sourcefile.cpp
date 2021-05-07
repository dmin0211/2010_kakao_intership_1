#include <iostream>
#include <string>
#include <vector>

using namespace std;
int length_input[50];

int solution(vector <vector<int>> board, vector<int> moves) {
  vector<int> answer;
  int result=0;
  int s=board.size();
  vector<vector<int>> input(s);
  for (int i = 0; i < s; ++i) {
    for (int j = 0; j < s; ++j) {
      if(board[j][i]==0)continue;
      input[i].push_back(board[j][i]);
    }
  }
  for (int i = 0; i < moves.size(); ++i) {
    int temp = moves[i]-1;
    if(length_input[temp]==input[temp].size()) continue;
    if (answer.size()==0){
        answer.push_back(input[temp][length_input[temp]]);
        length_input[temp]++;
        continue;
    }
    if(answer[answer.size()-1]==input[temp][length_input[temp]]){
      answer.pop_back();
      result = result+2;
    }else {
      answer.push_back(input[temp][length_input[temp]]);
    }
    length_input[temp]=length_input[temp]+1;
  }

  return result;
}

int main() {
  cout<<solution({{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}},
                 {1, 5, 3, 5, 1, 2, 1, 4})<<endl;
}