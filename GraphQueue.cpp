#include <iostream>
#include <vector>
#include <queue> // क्यू (Queue) का इस्तेमाल करने के लिए

using namespace std;

// ये हमारा मेन फंक्शन है जो ग्राफ में घूमेगा (BFS ट्रेवर्सल करेगा)
void bfs(int startNode, const vector<vector<int>>& adj, int totalNodes) {
    
    // 1. एक 'visited' लिस्ट बनाई ताकि जो नोड हम देख चुके हैं, वहाँ दोबारा न जाएं (चक्कर न काटते रहें)
    vector<bool> visited(totalNodes, false);
    
    // 2. अपनी लाइन (Queue) तैयार की, जिसमें नोड्स को बारी-बारी रखेंगे
    queue<int> q;

    // 3. सबसे पहले वाले नोड को 'visited' (सच्चा) मार्क किया और लाइन में सबसे आगे खड़ा कर दिया
    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS ट्रेवर्सल का रास्ता: ";

    // 4. अब जब तक हमारी लाइन (Queue) पूरी खाली नहीं हो जाती, तब तक ये लूप चलेगा
    while (!q.empty()) {
        
        // लाइन में जो सबसे आगे खड़ा है, उसे बाहर निकाला और currentNode नाम दे दिया
        int currentNode = q.front();
        q.pop(); // लाइन से हटा दिया क्योंकि अब इसकी बारी आ गई
        
        // उस नोड को स्क्रीन पर प्रिंट कर दिया
        cout << currentNode << " ";

        // 5. अब इस नोड के जितने भी पड़ोसी (neighbors) हैं, उन्हें एक-एक करके चेक करेंगे
        for (int neighbor : adj[currentNode]) {
            
            // अगर पड़ोसी को पहले कभी नहीं देखा (not visited), तो ही अंदर जाओ
            if (!visited[neighbor]) {
                
                visited[neighbor] = true; // अब इसे देख लिया है, तो टिक मार्क लगा दो
                q.push(neighbor);         // और इसको लाइन (Queue) में पीछे खड़ा कर दो
            }
        }
    }
    cout << endl; // लाइन खत्म, खेल खत्म!
}

int main() {
    int nodes = 5; // हमारे ग्राफ में कुल 5 नोड्स हैं (0 से लेकर 4 तक)
    
    // ग्राफ का नक्शा (Adjacency List) तैयार कर रहे हैं
    vector<vector<int>> adj(nodes);

    // यहाँ हम बता रहे हैं कि कौन सा नोड किससे जुड़ा हुआ है (Edges बना रहे हैं)
    adj[0] = {1, 2};    // 0 जुड़ा है 1 और 2 से
    adj[1] = {0, 3, 4}; // 1 जुड़ा है 0, 3 और 4 से
    adj[2] = {0};       // 2 जुड़ा है सिर्फ 0 से
    adj[3] = {1};       // 3 जुड़ा है सिर्फ 1 से
    adj[4] = {1};       // 4 जुड़ा है सिर्फ 1 से

    // चलो भाई, नोड 0 से घूमना (BFS) शुरू करते हैं!
    bfs(0, adj, nodes);

    return 0;
}