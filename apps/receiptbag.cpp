#include <iostream>
using namespace std;

class ReceiptBag:
{
   def __init__(self):
   {
       self.items = [];
       self.receipts = [];
   }
   
   def put(self, item):
   {
       rec = len(self.items);
       self.items.append(item);
       self.receipts.append(rec);
       return rec;
   }
   
   def remove(self, receipt):
   {
       for i in range(len(self.receipts)):
           if self.receipts[i] == rec:
           {
               removed = self.items[i];
               del self.items[i];
               del self.receipts[i];
               return removed;
           }
       return None;
   }
}
int main()
{
    return 0;
}
