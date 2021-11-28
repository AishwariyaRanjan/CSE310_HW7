Edge Part3(int[][] S, int * O){
    //storing paths of all possible lengths
    
    Edge path[S.length][S.length];
    //int x;

    for(int i=0; i<=S.length; i++){ //iterates through paths of diff lenghts
        for(int j=0; j<=S.length; j++){ // iterates through edges of one path length
            for(int x=1; x<=S.length; x++) // checks if edge in S is of length 1...numNodes
            if(S[i][j] == x){
                path[x][j+1].start = O[i];//need to put O[i] from part2
                //OR path[x][j]->start = ;
                path[x][j+1].end = O[j];//HOW TO GET EDGE's VERTICES // need to put O[j] from part2
                
                
            }          
        }        
    }

    Edge M[O.length];
    for(int i=0; i<=O.length; i++){
        M[i].start = -1;
        M[i].end = -1;
    }

    M[1].start = path[1][1].start;
    M[1].end = path[1][1].end;
    int index=2;
    int k=1;
    bool match=false;

     for(int i=1; i<=S.length; i++){ 
        for(int j=1; j<=S.length; j++){
        
            if(M[k] != -1){
                for(int n=1; n<index; n++){
                    if((path[i][j].start != (M[n].start||M[n].end)) && (path[i][j].end != (M[n].start||M[n].end))){
                        match = false;
                    }
                    else{
                        match = true;
                        break; 
                    }
                    
                }
                if(match == false){
                    M[index].start = path[i][j].start;
                    M[index].end = path[i][j].end;
                    M[index].weight = i;
                    index++;
                }                
            }            
        }
     }

    std::cout  << "The greedy perfect matching in O: M = {" ; 
    for(int i=1; i <= M.length; i++){
        std::cout << "(" << M[i].start << "," << M[i].end << ") ";
    }
    std::cout  << "}" << endl; 

    return M;
}