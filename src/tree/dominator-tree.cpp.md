---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/tree/dominator-tree.cpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstdint>\n#include <functional>\n#include\
    \ <iostream>\n#include <vector>\n\nusing std::cout;\nusing std::endl;\nusing std::vector;\n\
    \n// BeginCodeSnip{Tree Class for rdom}\ntemplate <typename T> class Tree {\n\
    \  private:\n\tconst int root = 0;\n\tconst vector<int> &parents;\n\tconst vector<T>\
    \ &vals;\n\tconst int log2dist;\n\tvector<vector<int>> pow2ends;\n\tvector<vector<T>>\
    \ pow2mins;\n\tvector<int> depth;\n\n  public:\n\tTree(const vector<int> &parents,\
    \ const vector<T> &vals)\n\t    : parents(parents), vals(vals),\n\t      log2dist(std::ceil(std::log2(parents.size()\
    \ + 1))),\n\t      pow2ends(parents.size(), vector<int>(log2dist + 1)),\n\t  \
    \    pow2mins(parents.size(), vector<T>(log2dist + 1)) {\n\t\tassert(parents[root]\
    \ == -1);\n\n\t\tvector<vector<int>> children(parents.size());\n\t\tfor (int n\
    \ = 0; n < parents.size(); n++) {\n\t\t\tif (parents[n] != -1) { children[parents[n]].push_back(n);\
    \ }\n\t\t}\n\t\tdepth = vector<int>(parents.size());\n\t\tvector<int> frontier{root};\n\
    \t\twhile (!frontier.empty()) {\n\t\t\tint curr = frontier.back();\n\t\t\tfrontier.pop_back();\n\
    \t\t\tfor (int n : children[curr]) {\n\t\t\t\tdepth[n] = depth[curr] + 1;\n\t\t\
    \t\tfrontier.push_back(n);\n\t\t\t}\n\t\t}\n\n\t\tfor (int n = 0; n < parents.size();\
    \ n++) {\n\t\t\tpow2mins[n][0] = vals[n];\n\t\t\tpow2ends[n][0] = parents[n];\n\
    \t\t}\n\t\tfor (int p = 1; p <= log2dist; p++) {\n\t\t\tfor (int n = 0; n < parents.size();\
    \ n++) {\n\t\t\t\tint halfway = pow2ends[n][p - 1];\n\t\t\t\tif (halfway == -1)\
    \ {\n\t\t\t\t\tpow2ends[n][p] = -1;\n\t\t\t\t\tpow2mins[n][p] = pow2mins[n][p\
    \ - 1];\n\t\t\t\t} else {\n\t\t\t\t\tpow2ends[n][p] = pow2ends[halfway][p - 1];\n\
    \t\t\t\t\tpow2mins[n][p] =\n\t\t\t\t\t    std::min(pow2mins[n][p - 1], pow2mins[halfway][p\
    \ - 1]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\t/**\n\t * @return the min value\
    \ on the path from the ancestor to its descendant,\n\t *         not including\
    \ the ancestor.\n\t */\n\tT min_val(int ancestor, int desc) {\n\t\tint dist =\
    \ depth[desc] - depth[ancestor];\n\t\tT ret = vals[desc];\n\t\tint at = desc;\n\
    \t\tfor (int pow = 0; pow <= log2dist; pow++) {\n\t\t\tif ((dist & (1 << pow))\
    \ != 0) {\n\t\t\t\tret = std::min(ret, pow2mins[at][pow]);\n\t\t\t\tat = pow2ends[at][pow];\n\
    \t\t\t}\n\t\t}\n\t\tassert(at == ancestor);\n\t\treturn ret;\n\t}\n};\n// EndCodeSnip\n\
    \nint main() {\n\tint city_num;\n\tint flight_num;\n\tstd::cin >> city_num >>\
    \ flight_num;\n\tvector<vector<int>> adj(city_num);\n\tvector<vector<int>> rev_adj(city_num);\n\
    \tfor (int f = 0; f < flight_num; f++) {\n\t\tint a, b;\n\t\tstd::cin >> a >>\
    \ b;\n\t\tadj[--a].push_back(--b);\n\t\trev_adj[b].push_back(a);\n\t}\n\n\t//\
    \ Variables used for the Euler Tour\n\tvector<int> visit_order;\n\t// visit_time\
    \ is initialized with INF so nodes that aren't reachable\n\t// during the DFS\
    \ won't mess up our sdom calculation\n\tvector<int> visit_time(city_num, INT32_MAX);\n\
    \tvector<int> visit_parent(city_num, -1);\n\tvector<bool> visited(city_num, false);\n\
    \tstd::function<void(int, int)> dfs;\n\tdfs = [&](int at, int prev) {\n\t\tif\
    \ (visited[at]) { return; }\n\t\tvisited[at] = true;\n\n\t\tvisit_time[at] = visit_order.size();\n\
    \t\tvisit_order.push_back(at);\n\t\tvisit_parent[at] = prev;\n\t\tfor (int next\
    \ : adj[at]) { dfs(next, at); }\n\t};\n\tdfs(0, -1);\n\n\t// We use a function-based\
    \ interface instead of a class-based one due to\n\t// heavy reliance on previously\
    \ calculated values\n\tvector<int> dsu_parent(city_num, -1);\n\tvector<int> dsu_min(city_num,\
    \ INT32_MAX);\n\tstd::function<int(int)> find;\n\tfind = [&](int x) {\n\t\tif\
    \ (dsu_parent[x] == -1) { return x; }\n\t\tif (dsu_parent[dsu_parent[x]] != -1)\
    \ {\n\t\t\tint parent_res = find(dsu_parent[x]);\n\t\t\tif (visit_time[parent_res]\
    \ < visit_time[dsu_min[x]]) {\n\t\t\t\tdsu_min[x] = parent_res;\n\t\t\t}\n\t\t\
    \tdsu_parent[x] = dsu_parent[dsu_parent[x]];\n\t\t}\n\t\tassert(dsu_min[x] !=\
    \ INT32_MAX);\n\t\treturn dsu_min[x];\n\t};\n\n\tvector<int> sdom(city_num, -1);\n\
    \tfor (int i = visit_order.size() - 1; i > 0; i--) {\n\t\tint c = visit_order[i];\n\
    \t\t// Iterate over all nodes with a directed edge to c\n\t\tfor (int from : rev_adj[c])\
    \ {\n\t\t\tint find_res = find(from);\n\t\t\t// Take the node with the earliest\
    \ visit time in the traversal\n\t\t\tif (sdom[c] == -1 || visit_time[find_res]\
    \ < visit_time[sdom[c]]) {\n\t\t\t\tsdom[c] = find_res;\n\t\t\t}\n\t\t}\n\n\t\t\
    // Link c to its parent in the DFS tree\n\t\tdsu_parent[c] = visit_parent[c];\n\
    \t\tdsu_min[c] = sdom[c];\n\t}\n\n\t// Initialize the values in the tree\n\tvector<std::pair<int,\
    \ int>> sdom_times(city_num, {INT32_MAX, -1});\n\tfor (int c : visit_order) {\n\
    \t\tif (c != 0) {\n\t\t\t// The tree takes the minimum of these pairs, but what\
    \ we\n\t\t\t// really want is the node itself- therefore, we store both\n\t\t\t\
    sdom_times[c] = {visit_time[sdom[c]], c};\n\t\t}\n\t}\n\tTree tree(visit_parent,\
    \ sdom_times);\n\n\tvector<int> rdom(city_num, -1);\n\tfor (int c : visit_order)\
    \ {\n\t\tif (c != 0) {\n\t\t\t// Use the definition of the rdom\n\t\t\trdom[c]\
    \ = tree.min_val(sdom[c], c).second;\n\t\t}\n\t}\n\n\t// Use the properties previously\
    \ given to compute the idom\n\tvector<int> idom(city_num, -1);\n\tfor (int c :\
    \ visit_order) {\n\t\tif (c != 0) { idom[c] = rdom[c] == c ? sdom[c] : idom[rdom[c]];\
    \ }\n\t}\n\n\t// Trace the idom tree from the finish node to the start node,\n\
    \t// finding all dominators along the way\n\tvector<int> critical{0};\n\tint at\
    \ = city_num - 1;\n\twhile (at != 0) {\n\t\tcritical.push_back(at);\n\t\tat =\
    \ idom[at];\n\t}\n\n\tstd::sort(critical.begin(), critical.end());\n\n\tcout <<\
    \ critical.size() << '\\n';\n\tfor (int i = 0; i < critical.size() - 1; i++) {\
    \ cout << critical[i] + 1 << ' '; }\n\tcout << critical.back() + 1 << endl;\n\
    }\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <cstdint>\n\
    #include <functional>\n#include <iostream>\n#include <vector>\n\nusing std::cout;\n\
    using std::endl;\nusing std::vector;\n\n// BeginCodeSnip{Tree Class for rdom}\n\
    template <typename T> class Tree {\n  private:\n\tconst int root = 0;\n\tconst\
    \ vector<int> &parents;\n\tconst vector<T> &vals;\n\tconst int log2dist;\n\tvector<vector<int>>\
    \ pow2ends;\n\tvector<vector<T>> pow2mins;\n\tvector<int> depth;\n\n  public:\n\
    \tTree(const vector<int> &parents, const vector<T> &vals)\n\t    : parents(parents),\
    \ vals(vals),\n\t      log2dist(std::ceil(std::log2(parents.size() + 1))),\n\t\
    \      pow2ends(parents.size(), vector<int>(log2dist + 1)),\n\t      pow2mins(parents.size(),\
    \ vector<T>(log2dist + 1)) {\n\t\tassert(parents[root] == -1);\n\n\t\tvector<vector<int>>\
    \ children(parents.size());\n\t\tfor (int n = 0; n < parents.size(); n++) {\n\t\
    \t\tif (parents[n] != -1) { children[parents[n]].push_back(n); }\n\t\t}\n\t\t\
    depth = vector<int>(parents.size());\n\t\tvector<int> frontier{root};\n\t\twhile\
    \ (!frontier.empty()) {\n\t\t\tint curr = frontier.back();\n\t\t\tfrontier.pop_back();\n\
    \t\t\tfor (int n : children[curr]) {\n\t\t\t\tdepth[n] = depth[curr] + 1;\n\t\t\
    \t\tfrontier.push_back(n);\n\t\t\t}\n\t\t}\n\n\t\tfor (int n = 0; n < parents.size();\
    \ n++) {\n\t\t\tpow2mins[n][0] = vals[n];\n\t\t\tpow2ends[n][0] = parents[n];\n\
    \t\t}\n\t\tfor (int p = 1; p <= log2dist; p++) {\n\t\t\tfor (int n = 0; n < parents.size();\
    \ n++) {\n\t\t\t\tint halfway = pow2ends[n][p - 1];\n\t\t\t\tif (halfway == -1)\
    \ {\n\t\t\t\t\tpow2ends[n][p] = -1;\n\t\t\t\t\tpow2mins[n][p] = pow2mins[n][p\
    \ - 1];\n\t\t\t\t} else {\n\t\t\t\t\tpow2ends[n][p] = pow2ends[halfway][p - 1];\n\
    \t\t\t\t\tpow2mins[n][p] =\n\t\t\t\t\t    std::min(pow2mins[n][p - 1], pow2mins[halfway][p\
    \ - 1]);\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t}\n\n\t/**\n\t * @return the min value\
    \ on the path from the ancestor to its descendant,\n\t *         not including\
    \ the ancestor.\n\t */\n\tT min_val(int ancestor, int desc) {\n\t\tint dist =\
    \ depth[desc] - depth[ancestor];\n\t\tT ret = vals[desc];\n\t\tint at = desc;\n\
    \t\tfor (int pow = 0; pow <= log2dist; pow++) {\n\t\t\tif ((dist & (1 << pow))\
    \ != 0) {\n\t\t\t\tret = std::min(ret, pow2mins[at][pow]);\n\t\t\t\tat = pow2ends[at][pow];\n\
    \t\t\t}\n\t\t}\n\t\tassert(at == ancestor);\n\t\treturn ret;\n\t}\n};\n// EndCodeSnip\n\
    \nint main() {\n\tint city_num;\n\tint flight_num;\n\tstd::cin >> city_num >>\
    \ flight_num;\n\tvector<vector<int>> adj(city_num);\n\tvector<vector<int>> rev_adj(city_num);\n\
    \tfor (int f = 0; f < flight_num; f++) {\n\t\tint a, b;\n\t\tstd::cin >> a >>\
    \ b;\n\t\tadj[--a].push_back(--b);\n\t\trev_adj[b].push_back(a);\n\t}\n\n\t//\
    \ Variables used for the Euler Tour\n\tvector<int> visit_order;\n\t// visit_time\
    \ is initialized with INF so nodes that aren't reachable\n\t// during the DFS\
    \ won't mess up our sdom calculation\n\tvector<int> visit_time(city_num, INT32_MAX);\n\
    \tvector<int> visit_parent(city_num, -1);\n\tvector<bool> visited(city_num, false);\n\
    \tstd::function<void(int, int)> dfs;\n\tdfs = [&](int at, int prev) {\n\t\tif\
    \ (visited[at]) { return; }\n\t\tvisited[at] = true;\n\n\t\tvisit_time[at] = visit_order.size();\n\
    \t\tvisit_order.push_back(at);\n\t\tvisit_parent[at] = prev;\n\t\tfor (int next\
    \ : adj[at]) { dfs(next, at); }\n\t};\n\tdfs(0, -1);\n\n\t// We use a function-based\
    \ interface instead of a class-based one due to\n\t// heavy reliance on previously\
    \ calculated values\n\tvector<int> dsu_parent(city_num, -1);\n\tvector<int> dsu_min(city_num,\
    \ INT32_MAX);\n\tstd::function<int(int)> find;\n\tfind = [&](int x) {\n\t\tif\
    \ (dsu_parent[x] == -1) { return x; }\n\t\tif (dsu_parent[dsu_parent[x]] != -1)\
    \ {\n\t\t\tint parent_res = find(dsu_parent[x]);\n\t\t\tif (visit_time[parent_res]\
    \ < visit_time[dsu_min[x]]) {\n\t\t\t\tdsu_min[x] = parent_res;\n\t\t\t}\n\t\t\
    \tdsu_parent[x] = dsu_parent[dsu_parent[x]];\n\t\t}\n\t\tassert(dsu_min[x] !=\
    \ INT32_MAX);\n\t\treturn dsu_min[x];\n\t};\n\n\tvector<int> sdom(city_num, -1);\n\
    \tfor (int i = visit_order.size() - 1; i > 0; i--) {\n\t\tint c = visit_order[i];\n\
    \t\t// Iterate over all nodes with a directed edge to c\n\t\tfor (int from : rev_adj[c])\
    \ {\n\t\t\tint find_res = find(from);\n\t\t\t// Take the node with the earliest\
    \ visit time in the traversal\n\t\t\tif (sdom[c] == -1 || visit_time[find_res]\
    \ < visit_time[sdom[c]]) {\n\t\t\t\tsdom[c] = find_res;\n\t\t\t}\n\t\t}\n\n\t\t\
    // Link c to its parent in the DFS tree\n\t\tdsu_parent[c] = visit_parent[c];\n\
    \t\tdsu_min[c] = sdom[c];\n\t}\n\n\t// Initialize the values in the tree\n\tvector<std::pair<int,\
    \ int>> sdom_times(city_num, {INT32_MAX, -1});\n\tfor (int c : visit_order) {\n\
    \t\tif (c != 0) {\n\t\t\t// The tree takes the minimum of these pairs, but what\
    \ we\n\t\t\t// really want is the node itself- therefore, we store both\n\t\t\t\
    sdom_times[c] = {visit_time[sdom[c]], c};\n\t\t}\n\t}\n\tTree tree(visit_parent,\
    \ sdom_times);\n\n\tvector<int> rdom(city_num, -1);\n\tfor (int c : visit_order)\
    \ {\n\t\tif (c != 0) {\n\t\t\t// Use the definition of the rdom\n\t\t\trdom[c]\
    \ = tree.min_val(sdom[c], c).second;\n\t\t}\n\t}\n\n\t// Use the properties previously\
    \ given to compute the idom\n\tvector<int> idom(city_num, -1);\n\tfor (int c :\
    \ visit_order) {\n\t\tif (c != 0) { idom[c] = rdom[c] == c ? sdom[c] : idom[rdom[c]];\
    \ }\n\t}\n\n\t// Trace the idom tree from the finish node to the start node,\n\
    \t// finding all dominators along the way\n\tvector<int> critical{0};\n\tint at\
    \ = city_num - 1;\n\twhile (at != 0) {\n\t\tcritical.push_back(at);\n\t\tat =\
    \ idom[at];\n\t}\n\n\tstd::sort(critical.begin(), critical.end());\n\n\tcout <<\
    \ critical.size() << '\\n';\n\tfor (int i = 0; i < critical.size() - 1; i++) {\
    \ cout << critical[i] + 1 << ' '; }\n\tcout << critical.back() + 1 << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/dominator-tree.cpp
  requiredBy: []
  timestamp: '2025-09-05 00:27:18+07:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/tree/dominator-tree.cpp
layout: document
redirect_from:
- /library/src/tree/dominator-tree.cpp
- /library/src/tree/dominator-tree.cpp.html
title: src/tree/dominator-tree.cpp
---
