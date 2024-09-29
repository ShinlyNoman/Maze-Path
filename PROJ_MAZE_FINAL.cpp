#include<iostream>
using namespace std;

int maze[20][20];
int visited[20][20];
int taken[20][20];


void display_input(int n){

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){

            cout<<maze[row][col]<<" ";
        }
        cout<<endl;
    }
}


bool dfs(int row, int col, int n, int dest_row, int dest_col){

    bool path1=false, path2=false, path3=false, path4=false;


    if(row >= n || col >= n ||row<0 ||col<0){
        return false;
    }


    if(row==dest_row && col==dest_col){
        return true;
    }
    visited[row][col]=1;



    if(row+1<n && maze[row+1][col]==1){
        if(visited[row+1][col]==0){
            path1 = dfs(row+1, col, n, dest_row, dest_col);
            if(path1){
                taken[row][col] = 1;
                return true;
            }

        }
    }


    if(col+1<n && maze[row][col+1]==1){
        if(visited[row][col+1]==0){
            path2 = dfs(row, col+1, n, dest_row, dest_col);
            if(path2){
                taken[row][col] = 1;
                return true;
            }

        }
    }


    if(col-1>=0 && maze[row][col-1]==1){
        if(visited[row][col-1]==0){
            path3 = dfs(row, col-1, n, dest_row, dest_col);
            if(path3){
                taken[row][col] = 1;
                return true;
            }

        }
    }


    if(row-1>=0 && maze[row-1][col]==1){
        if(visited[row-1][col]==0){
            path4 = dfs(row-1, col, n, dest_row, dest_col);
            if(path4){
                taken[row][col] = 1;
                return true;
            }

        }
    }
}

void display_output(int n){

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){

            cout<<taken[row][col]<<" ";
        }
        cout<<endl;
    }
}



int main(){

    int n=4, row, col;

    for(int row=0;row<n;row++){
        for(int col=0;col<n;col++){
            maze[row][col]=1;
            visited[row][col]=0;
        }
    }



    maze[0][1]=0;
    maze[0][2]=0;
    maze[0][3]=0;
    maze[1][2]=0;
    maze[2][0]=0;

    maze[2][2]=0;
    maze[2][3]=0;


    cout<<"Input Maze:";
    cout<<endl;
    display_input(n);

    dfs(0, 0, n, 3, 3);

    cout<<"Solved maze:";
    cout<<endl;
    display_output(n);
return 0;
}
