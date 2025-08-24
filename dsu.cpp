// do hi operation pe work krta h ye khaali -> 
//         1) find.   
//         2) union

int find(int i, vector<int> &parent){
    //find kisko krna h? "i ko krna h"
    //parent ki jrurat to hogi hi bcs vhi logic to seekha hai apan ne ki ek set ka head jo hota h whi find() find krke dega, to obv h ki parent vector to daalna pdega

    if(i == parent[i]){
        //agar jiska baap nikaalna h vo khud hi baap h yaani jiska parent nikaalre h, vo khud hi agar uske set ka parent h to vhi stop hojaate h apan and whi return krte h so
        return i;
    }

    return parent[i] = find(parent[i], parent);
    //vrna recursn dodado, yahi to algo way me bhi kiye the copy vopy me.
}

void union(int x,int y, vector<int> &parent){
    //isme tum union kroge 2 set ka, and fir parent vector me change bhi kroge usi hisaab se ki final dono ka parent kon h ab to isliye ye sab lenge andar fn ke
    int x_par = find(x,parent);
    int y_par = find(y, parent);

    //theeke dono ke papa nikaal liye apan ne ab?
    //vhi logic lagao ki kisi ek ko banado dono ka papa aftre u took em in ur chatrachaaya
    if(x_par != y_par){
        parent[x_par] = y_par; //vica-versa bhi likh skte ho depeneding on teh question.
    }
}



//we have rank union fn too, which's much more efficient bcs vo graph smaller banata hai to reduce recurssion
void union(int x, int y, vector<int> &parent, vector<int> &rank){
    int x_par = find(x, parent);
    int y_par = find(y, parent);

    if(x_par == y_par){
        return;
    }

    //rank ke hisaab se parent select hoga!
    if(rank[x_par] > rank[y_par]){ //jiska rank bada vo papa simple.
        parent[y_par] = x_par;
    }else if(rank[y_par] > rank[x_par]){
        parent[x_par] = y_par;
    }else if (rank[x_par] == rank[y_par]){
        rank[y_par]++; //jisko parent bnaare uska rank ++ krdo tabhi to differinciate kr paayenge apan ki rank same h ki bada ki kya
        parent[x_par] = y_par;
    }
}




// When to choose which:
// Use Union by Rank: When you only care about connectivity

// Use Union by Size: When you need to know the size of connected components


void Union(int x, int y) {
    int x_root = find(x);
    int y_root = find(y);
    
    if (size[x_root] < size[y_root]) {
        parent[x_root] = y_root;
        size[y_root] += size[x_root];
    } else {
        parent[y_root] = x_root;
        size[x_root] += size[y_root];
    }
}