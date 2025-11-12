struct SAM {
  struct State {
    int len;
    State* link;
    map<char, State*> next;
  };
  State *first, *last;
  SAM() { first = last = new State(); }
  SAM(string& s) : SAM() {
    for (int i = 0; i < s.size(); i++) add(s[i]);
  }
  void add(char ch) {
    State* nw = new State();
    nw->len = last->len + 1;
    nw->link = first;
    State* cur = last;
    while (cur && !cur->next[ch]) {
      cur->next[ch] = nw;
      cur = cur->link;
    }
    if (cur && cur->next[ch] != nw) {
      State* mid = cur->next[ch];
      if (cur->len + 1 == mid->len) {
        nw->link = mid;
      } else {
        State* clone = new State(*mid);
        clone->len = cur->len + 1;
        nw->link = mid->link = clone;
        while (cur && cur->next[ch] == mid) {
          cur->next[ch] = clone;
          cur = cur->link;
        }
      }
    }
    last = nw;
  }
};
