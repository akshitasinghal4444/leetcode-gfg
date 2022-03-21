
class RandomizedSet {
public:
    unordered_map<int,int> m;
    vector<int> v;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        
        if(m.find(val)!=m.end())
            return 0;
        
        v.push_back(val);
        m[val]=v.size()-1;
        return 1;
    }
    
    bool remove(int val) {
        
        if(m.find(val)==m.end())
            return 0;
        
        int i=m[val];
        v[i]=v.back();
        m[v.back()]=i;
        
        v.pop_back();
        m.erase(val);

        return 1;
    }
    
    //     bool remove(int val) {
    //         int last=a.back();  // back() fetches last element of the array vector
    //         a[m[val]]=a.back(); // m[val] locates the index of val in the array vector.
    // // Then we copy array last element value to the val location in the array
    //         a.pop_back();	    // Delete the last element of the array 
    //         m[last]=m[val];	    // In hashmap, assign index of val in array to the index of the last element   
    //         m.erase(val);	    // Delete the val entry from map
    //         return true;
    //     }
    // }
    
    int getRandom() {
        int x=rand()%(v.size());
        return v[x];
    }
};


/*
class RandomizedSet {
	// Optimal Solution Time O(1) & Auxiliary Space O(N)
private:
    vector<int> a; // array vector
    unordered_map<int,int> m; // Unordered Map does searching, insertion & deletion of element in O(1) time
public:

    RandomizedSet() {
    // No need to initialise a & m as they are initialised automatically
	// to 0 as and when their container size increases.
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end())
	        // If val is not already present in the map, find() function  
	        // returns an iterator(m.end()) pointing to next memory location  
            // of the last element of the map. Otherwise, find() returns an iterator 
            // pointing to val which was already present in the map.  
            return false;
        else{
            a.push_back(val);  // insert val at the end of the array
            m[val]=a.size()-1; // m[key,value] stores the array element and 
			                   // its index as key=array element & value=array element index
            return true;
        }
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()) // val not present in the array vector
            return false;
        else{
	        // val present in the array vector
	        // For example: a=[8,4,3,2], m={[8,0],[4,1],[3,2],[2,3]}, val=4, last=2
	        // After a[m[val]]=a.back(); a=[8,2,3,2], m={[8,0],[4,1],[3,2],[2,3]}
	        // After a.pop_back(); a=[8,2,3], m={[8,0],[4,1],[3,2],[2,3]}
	        // After m[last]=m[val]; a=[8,2,3], m={[8,0],[4,1],[3,2],[2,1]}
	        // After m.erase(val); a=[8,2,3], m={[8,0],[3,2],[2,1]}
            int last=a.back();  // back() fetches last element of the array vector
            a[m[val]]=a.back(); // m[val] locates the index of val in the array vector.
				                // Then we copy array last element value to the val location in the array
            a.pop_back();	    // Delete the last element of the array 
            m[last]=m[val];	    // In hashmap, assign index of val in array to the index of the last element   
            m.erase(val);	    // Delete the val entry from map
            return true;
        }
    }
    
    int getRandom() {
	    // rand() function gives random value in the range of 0 to RAND_MAX(whose value is 32767). x%y gives 
 	    // remainder when x is divided by y and this remainder is in the range of 0 to y-1.
	    // rand()%a.size() gives random value in the range of (0 to a.size()-1).
	    // a[rand()%a.size()] will give random value of array in the range of a[0] to a[a.size()-1].
        return a[rand()%a.size()];
    }
};
*/

/*
class RandomizedSet {
public:
    unordered_set<int> s;
    unordered_map<int,int> m1,m2;
    int i;
    
    RandomizedSet() {
        i=0;
    }
    
    bool insert(int val) {
        
        if(m1.find(val)==m1.end())
        {   
            m1[val]=i;
            m2[i]=val;
            s.insert(i);
            i++;
            
            return 1;
        }
        return 0;
    }
    
    bool remove(int val) {
        if(m1.find(val)!=m1.end())
        {
            int in=m1[val];
            
            s.erase(in);
            m2.erase(in);            
            m1.erase(val);
            
            i--;
            if(m2.find(i)!=m2.end())
            {
                val=m2[i];
                
                s.erase(i);
                m2.erase(i);
                
                m1[val]=in;
                m2[in]=val;
                s.insert(in);
            }
            return 1;
        }
        return 0;
    }
    
    int getRandom() {
        
        int n=s.size();
        int x=rand()%n;
        
        return m2[x];
    }
};
*/

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */