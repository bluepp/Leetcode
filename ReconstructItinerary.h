/*
bluepp
2016-06-23
May the force be with me!

https://leetcode.com/problems/reconstruct-itinerary/

Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.

*/

/* https://leetcode.com/discuss/87314/non-recursive-time-space-solution-with-detail-explanations */

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        
       // Step 1: Store directed edges in a hash map
        unordered_map<string, multiset<string>> m;
        for (const pair<string, string> & ticket : tickets) {
            m[ticket.first].insert(ticket.second);
        }

        // Step 2: March greedily and traceback
        vector<string> march = { "JFK" }; // the storage for greedy searching
        vector<string> results; // store the final results reversely
        while (march.empty() == false) {
            string & from = march.back();
            if ((m.find(from) != m.end()) && (m[from].empty() == false)) { // march further
                multiset<string> & to = m[from];
                march.push_back(*(to.begin()));
                to.erase(to.begin());
            } else { // can not march further, trace back
                results.push_back(march.back()); // archive the last place
                march.pop_back();
            }
        }
        reverse(results.begin(), results.end()); // reverse the entries back
        return results;
        
    }
