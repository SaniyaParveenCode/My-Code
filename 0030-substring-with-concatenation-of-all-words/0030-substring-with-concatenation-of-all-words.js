var findSubstring = function(s, words) {
    let map = new Map();
    words.forEach(n => map.set(n, map.get(n) + 1 || 1));
    let size = words[0].length;
    let limit = s.length - size * words.length;
    let res = [];
    for(let i = 0; i <= limit; i++){
        if(map.get(s.substring(i, i+size))){
            let temp = new Map();
            let j = i;
            let count = 0;
            while(count<words.length){
                let str = s.substring(j, j+size);
                temp.set(str, temp.get(str) + 1 || 1);
                if(!map.get(str)||temp.get(str)>map.get(str)) break;
                j+=size;
                count++;
            }
            if(count===words.length) res.push(i);  
    }}
    return res;
};