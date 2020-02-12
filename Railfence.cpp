
#include <bits/stdc++.h> 
using namespace std; 
  

string encryptRailFence(string text, int key) 
{ 
    
    char railmatrix[key][(text.length())]; 
  
    for (int i=0; i < key; i++) 
        for (int j = 0; j < text.length(); j++) 
            railmatrix[i][j] = '\n';
  
    bool dir_down = false; 
    int row = 0, col = 0; 
  
    for (int i=0; i < text.length(); i++) 
    { 
        if (row == 0 || row == key-1) 
            dir_down = !dir_down; 
  
    
        railmatrix[row][col++] = text[i]; 
  
     
        dir_down?row++ : row--; 
    } 
  
  
    string result; 
    for (int i=0; i < key; i++) 
        for (int j=0; j < text.length(); j++) 
            if (railmatrix[i][j]!='\n') 
                result.push_back(railmatrix[i][j]); 
  
    return result; 
} 
  
 
string decryptRailFence(string cipher, int key) 
{ 
   
    char railmatrix[key][cipher.length()]; 
  
    
    for (int i=0; i < key; i++) 
        for (int j=0; j < cipher.length(); j++) 
            railmatrix[i][j] = '\n'; 
  
    
    bool dir_down; 
  
    int row = 0, col = 0; 
  
    
    for (int i=0; i < cipher.length(); i++) 
    { 
       
        if (row == 0) 
            dir_down = true; 
        if (row == key-1) 
            dir_down = false; 
  
        
        railmatrix[row][col++] = '*'; 
  
         
        dir_down?row++ : row--; 
    } 
  
    
    int index = 0; 
    for (int i=0; i<key; i++) 
        for (int j=0; j<cipher.length(); j++) 
            if (railmatrix[i][j] == '*' && index<cipher.length()) 
                railmatrix[i][j] = cipher[index++]; 
  
  
     
    string result; 
  
    row = 0, col = 0; 
    for (int i=0; i< cipher.length(); i++) 
    { 
        
        if (row == 0) 
            dir_down = true; 
        if (row == key-1) 
            dir_down = false; 
  

        if (railmatrix[row][col] != '*') 
            result.push_back(railmatrix[row][col++]); 
          dir_down?row++: row--; 
    } 
    return result; 
} 
  
int main() 
{ 
	string enc,dec;
    enc=encryptRailFence("attack at once", 2);
	cout<<enc<<endl;  
  
	dec=decryptRailFence(enc,2);
	cout<<dec<<endl; 
     
  
    return 0; 
}
