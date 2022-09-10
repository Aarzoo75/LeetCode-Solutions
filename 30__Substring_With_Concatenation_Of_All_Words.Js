var findSubstring = function(s, words) {
    const wordLength = words[0].length;
    const result = [];
  
    const unique = [...new Set(words)];
  
    const clearMap = {};
    for (let i = 0; i < unique.length; i++) {
      clearMap[unique[i]] = 0;
    }
  
    const wordsMap = {...clearMap};
  
    for (let i = 0; i < words.length; i++) {
      wordsMap[words[i]]++;
    }
  
    const groups = {};
      
    const matches = s.matchAll(new RegExp(`(?=(${unique.join("|")}))`, "g"));
    for (const match of matches) {
      const groupIndex = match.index % wordLength;
  
      let {currentItems, currentMap} = groups[groupIndex] = groups[groupIndex] || {
        currentItems: [],
        currentMap: {...clearMap}
      };
  
      if (currentItems.length && match.index != currentItems[currentItems.length - 1].index + wordLength) {
        currentItems.length = 0;
        currentMap = groups[groupIndex].currentMap = {...clearMap};
      }
  
      currentMap[match[1]]++;
      currentItems.push({index: match.index, word: match[1]});
  
      if (currentItems.length < words.length) {
        continue;
      }
  
      if (currentItems.length > words.length) {
        currentMap[currentItems.shift().word]--;
      }
  
      if (unique.every(word => currentMap[word] === wordsMap[word])) {
        result.push(currentItems[0].index);
      }
    }
  
    return result;
  };