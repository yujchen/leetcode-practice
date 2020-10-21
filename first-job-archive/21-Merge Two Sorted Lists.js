/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function(l1, l2) {
    if (l1 === null){
        return l2;
    }
    if (l2 === null){
        return l1;
    }
    /*
    let x = JSON.stringify(l1);
    console.log(x); 
    prints out {"val":1,"next":{"val":2,"next":{"val":4,"next":null}}}
    */
    
    /*Extract values from the list and create new link list*/
    let x = [];
    while (l1 || l2){
        if (l1.val < l2.val){
            //console.log(l1.val);
            x.push(l1.val);
            l1 = l1.next
        }
        else{
            //console.log(l2.val);
            x.push(l2.val);
            l2 = l2.next
        }
        if (!l1){
            //console.log(l2.val);
            x.push(l2.val);
            l2 = l2.next;
        }
        if (!l2){
            //console.log(l1.val);
            x.push(l1.val);
            l1 = l1.next;
        }
    }
    let lnew = new ListNode(0); //first create initial head node.
    let og = lnew;              //Save reference to head.
    while(x.length){
        lnew.val = x.shift();
        if (x.length > 0){
            lnew.next = new ListNode(0);
            lnew = lnew.next;
        }
    }
    return og;
};

