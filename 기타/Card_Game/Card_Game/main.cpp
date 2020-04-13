#include <iostream>
using namespace std;
//arr[][] 변수는 fixedMatrix와 randomMatrix등 여러 함수에 쓰여서 전역변수로 설정하였다.
int arr[4][4]= {{1,2,3,4},
                {5,6,7,8},
                {8,7,6,5},
                {4,3,2,1}};
// a,b는 cardGame함수에서 두 행렬좌표(카드)를 선택할 때 쓰는 변수이다.
int a, b;

/*
 cardGame() : fixedMatrix 또는 randomMatrix로 부터 호출을 받아 실행되는 카드게임 함수이다.
 
 >> 조건 1: 두 카드쌍이 서로 일치하고 방문한 적이 없는 경우
    - 위 조건을 만족하는 경우 점수를 1 증가시킨다.(단, 7의 경우 2점)
    - 해당 카드쌍의 인덱스에 대해 방문을 체크한다. (visit[][] = true)
    - 만약 방문한 인덱스라면 해당 행렬 요소를 출력해주고 방문하지 않은 인덱스라면 'X'를 출력해준다.
 
 >> 조건 2: 만약 두 카드쌍이 서로 일치하지 않거나 방문한 적이 있는 경우
    - 위 조건을 만족하는 경우 현재 플레이어가 어느 카드를 선택했는지에 대해서만 출력해준다.
 
 >> 문제 상 전체 9점이 되면 승자가 나오게 되므로 9점일 경우 while-loop를 종료한다. --> 어느 플레이어가 승리하였는지 출력.
 */
void cardGame(int arr[][4]){
    bool visitP1[4][4] = {0,};  //플레이어 1의 카드가 쌍이 맞으면 방문했음을 표시한다.
    bool visitP2[4][4] = {0,};  //플레이어 2의 카드가 쌍이 맞으면 방문했음을 표시한다.

    cout<<"------------------------------"<<'\n';
    cout<<"*  Welcome to the card game  *"<<'\n';
    cout<<"|----------------------------|"<<'\n';
    cout<<"| Please Enter the two Point |"<<'\n';
    cout<<"| ex) (1,1), (4,4) : 11 44   |"<<'\n';
    cout<<"| Input Number: 1 ~ 4        |"<<'\n';
    cout<<"------------------------------"<<'\n';
    
    int cntP1 = 0;  //플레이어 1이 카드 쌍을 맞출 때 점수를 표현하기 위한 변수.
    int cntP2 = 0;  //플레이어 2가 카드 쌍을 맞출 때 점수를 표현하기 위한 변수.
    while(1){
        cout<<"P1's turn, choose two cards: ";
        cin>>a>>b;  //두 카드 입력.
        //두 자리 수로 입력받았기 때문에, 행에 해당하는 숫자는 10의 자리수, 열에 해당하는 수는 1의 자리수 이다.
        //따라서 '숫자'/10 = '행'이 되고 '숫자'%10 = '열'이 되도록 인덱스를 설정해준다.
        if(arr[a/10-1][a%10-1] == arr[b/10-1][b%10-1] && !visitP1[a/10-1][a%10-1] && !visitP1[b/10-1][b%10-1]){
            if(arr[a/10-1][a%10-1] == 7)
                cntP1 += 2;         //찾은 쌍이 7인경우에 2점추가라는 특별 경우.
            else
                cntP1 += 1;         //쌍을 찾으면 1점추가
            
            visitP1[a/10-1][a%10-1] = true; //쌍을 찾으면 방문하였다고 표시
            visitP1[b/10-1][b%10-1] = true;
            
            cout<<"    1 2 3 4\n";
            cout<<"--+--------\n";
            for(int i=0; i<4; i++){
                cout<<i+1<<" | ";
                for(int j=0; j<4; j++){
                    if(visitP1[i][j]) //방문한 쌍을 찾으면 해당 인덱스 출력
                        cout<<arr[i][j]<<' ';
                    else//아직 찾지 못한 경우엔 카드 뒷면 출력
                        cout<<'X'<<' ';
                }
                cout<<'\n';
            }
            cout<<"P1 found a matching pair! P1's score = "<<cntP1<<", P2's score = "<<cntP2<<'\n';
        }
        else{
            cout<<"Already Checked or Not Match. Please Enter It Next Turn."<<'\n';
            cout<<"> Currently Selected Cards.\n";
            cout<<"    1 2 3 4\n";
            cout<<"--+--------\n";
            for(int i=0; i<4; i++){
                cout<<i+1<<" | ";
                for(int j=0; j<4; j++){
                    if((i==a/10-1 && j==a%10-1) || (i==b/10-1 && j==b%10-1))    //현재 어떤 카드를 선택하였는지 알기 위해..
                        cout<<arr[i][j]<<' ';
                    else
                        cout<<'X'<<' ';
                }
                cout<<'\n';
            }
        }
        /*
         플레이어 1의 코드와 대부분 일치하며
         플레이어 2를 표현해주기 위해
         visitP1 --> visitP2, cntP1 --> cntP2의 변수들로 바꾸었습니다.
         */
        cout<<'\n';
        cout<<"P2's turn, choose two cards: ";
        cin>>a>>b;
        if(arr[a/10-1][a%10-1] == arr[b/10-1][b%10-1] && !visitP2[a/10-1][a%10-1] && !visitP2[b/10-1][b%10-1]){
            if(arr[a/10-1][a%10-1] == 7)
                cntP2 += 2;         //찾은 쌍이 7인경우에 2점추가라는 특별 경우.
            else
                cntP2 += 1;         //쌍을 찾으면 1점추가
            
            visitP2[a/10-1][a%10-1] = true; //쌍을 찾으면 방문하였다고 표시
            visitP2[b/10-1][b%10-1] = true;
            
            cout<<"    1 2 3 4\n";
            cout<<"--+--------\n";
            for(int i=0; i<4; i++){
                cout<<i+1<<" | ";
                for(int j=0; j<4; j++){
                    if(visitP2[i][j]) //쌍을 찾으면 해당 인덱스 출력
                        cout<<arr[i][j]<<' ';
                    else//아직 찾지 못한 경우엔 카드 뒷면 출력
                        cout<<'X'<<' ';
                }
                cout<<'\n';
            }
            cout<<"P2 found a matching pair! P1's score = "<<cntP1<<", P2's score = "<<cntP2<<'\n';
        }
        else{
            cout<<"Already Checked or Not Match. Please Enter It Next Turn.\n";
            cout<<"> Currently Selected Cards.\n";
            cout<<"    1 2 3 4\n";
            cout<<"--+--------\n";
            for(int i=0; i<4; i++){
                cout<<i+1<<" | ";
                for(int j=0; j<4; j++){
                    if((i==a/10-1 && j==a%10-1) || (i==b/10-1 && j==b%10-1))
                        cout<<arr[i][j]<<' ';
                    else
                        cout<<'X'<<' ';
                }
                cout<<'\n';
            }
        }
        cout<<"----------------------------"<<'\n';
        
        
        if(cntP1 == 9 || cntP2 == 9)//모든 쌍을 찾으면 원래 8점인데 7의 경우 2점을 부여하므로 최대 점수는 9점이 된다. 9점이 될 경우 종료한다.
            break;
    }
    
    
    if(cntP1 > cntP2)
        cout<<">>  P1 WIN!"<<'\n';
    else
        cout<<">>  P2 WIN!"<<'\n';
}


/*
 fixedMatrix(): 고정 배치에 해당하는 함수.
 
 >> 전역변수로 설정해놓은 arr[][]의 값을 array[][]에 할당해주었고
    array를 cardGame 함수에 return 해 주었다.
 */

void fixedMatrix(int arr[][4]){     //고정 배치
    int array[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            array[i][j] = arr[i][j];
        }
    }
    cardGame(array);
}

/*
 randomMatix(): 무작위 배치에 해당하는 함수.
 
 >> 1차원 배열인 inputArr에 1~8을 2번씩 초기화한다.
    inputArr을 for-loop와 rand()를 이용하여 무작위로 자리를 배치한다.
    따라서 inputArr의 배열의 값은 무작위로 배치된다.
    inputArr을 arr[][]에 할당해주는데, 이때 1차원 배열을 2차원 배열에 맞게 값을 할당해야한다.
    arr[i][j] <--> inputArr[i*4 + j]   이렇게 표현해주면 1차원 배열을 2차원 배열과 같은 의미로 가져갈 수 있다. (조사하여 새롭게 공부하게 되었다.)
    arr을 cardGame 함수에 return 해 주었다.
*/
void randomMatix(int arr[][4]){     // 무작위 배치
    srand((unsigned int)time(nullptr));
    int inputArr[] = {1,2,3,4,5,6,7,8,1,2,3,4,5,6,7,8};
    for(int i=0; i<16; i++){
        int s1 = rand()%8+1;
        int s2 = rand()%8+1;
        
        int temp = inputArr[s1];
        inputArr[s1] = inputArr[s2];
        inputArr[s2] = temp;
    }   // 카드 셔플링을 위한 내용.
    
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            arr[i][j] = inputArr[i*4+j];
        }
    }
    cardGame(arr);
}

/*
 GetCommand(): 출력문을 참고하여 1,2,0 중 숫자를 선택하여 입력한다. 입력한 숫자를 반환하는 함수이다.
*/
int GetCommand(){
    int command;
    cout << endl << endl;
    cout << "\t---ID -- Command ----- " << endl;
    cout << "\t   1 : 고정 배치 " << endl;
    cout << "\t   2 : 무작위 배치 " << endl;
    cout << "\t   0 : 프로그램 종료 " << endl;
    cout << endl << "\t Choose a Command--> ";
    cin >> command;
    cout << endl;
    return command;
}

/*
 Run(): GetCommand() 함수에서 입력 값을 받아, switch문을 통하여 선택 번호에 해당한 함수를 실행한다.
 */
void Run(){
    while(1) {
        int m_Command = GetCommand();
        switch(m_Command){
            case 1:
                fixedMatrix(arr);
                break;
            case 2:
                randomMatix(arr);
                break;
            case 0:
                return;
            default:    // 맞지 않는 숫자를 입력했을 때의 출력
                cout << "\t Illegal selection...\n";
                break;
                
        }
    }
}

int main() {
    Run();  // 고정 배치, 무작위 배칭에 대한 프로그램 모드 함수를 호출한다.
    return 0;
}

