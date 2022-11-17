// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h> //malloc
// // #include <malloc.h>

// // linked list -> salah satu cara untuk menginput data secara dynamic

// // --> single linked list
// // - Dalam link list struct disebut node
// // - Node pertama = head, node terakhir = tail
// // malloc -> dynamic memory allocation

// // --> double linked list
// // --> multipled linked list
// // --> multilevel linked list

// // di SLL punya 3 cara push
// // - Push Head -> menginsert dari depan
// // - Push Tail  -> menginsert dari belakang
// // - Push Mid

// // pop
// // popHead
// // popTail
// // popMid -> kasih parameter

// struct Mahasiswa{
// 	int nim;
// 	char name[255];
// 	double gpa;
// 	struct Mahasiswa *next;
// }*head = NULL, *tail=NULL;

// // Pabrik Node
// struct Mahasiswa *createNode(int nim, char name[], double gpa){
// 	struct Mahasiswa *node = (struct Mahasiswa*)malloc(sizeof(struct Mahasiswa));
// //	node->nim = nim;
// 	(*node).nim = nim;
// 	node->gpa = gpa;
// 	strcpy(node->name, name);
// 	node->next = NULL;
// 	return node;
// }

// void pushHead(int nim, char name[], double gpa){
// 	struct Mahasiswa *node = createNode(nim, name, gpa);
// 	// ketika tidak ada node di SLL -> single linked list
// 	if(head==NULL){
// 		head = tail = node;
// 	}
// 	// ketika ada node di SLL
// 	else {
// 		node->next = head;
// 		head = node;
// 	}
// }

// void pushTail (int nim, char name[], double gpa){
// 	struct Mahasiswa *node = createNode(nim, name, gpa);
// 	// ketika tidak ada node di SLL -> single linked list
// 	if(head==NULL){
// 		head = tail = node;
// 	}
// 	// ketika ada node di SLL
// 	else {
// 		tail->next = node ;
// 		tail = node;
// 	}
// }

// void pushMid (int nim, char name[], double gpa){
// 	struct Mahasiswa *node = createNode(nim, name, gpa);
// 	// memiliki 4 kondisi
// 	// tidak ada node
// 	if(head==NULL){
// 		head=tail=node;
// 	}
// 	//if data bagian head lebih besar dari node
// 	else if (head->nim > node->nim){
// 		pushHead(nim, name, gpa);
// 	}
// 	// if data bagian tail lebih kecil dari node
// 	else if(tail->nim < node->nim){
// 		pushTail(nim, name, gpa);
// 	}
// 	// if data berada ditengah
// 	else{
// 		struct Mahasiswa  *curr = head;
// 		while(curr->next->nim < node->nim){
// 			curr= node->next;
// 		}
// 		node->next = curr->next;
// 		curr->next = node;
// 	}
// }

// void popHead(){
// 	// tidak ada data
// 	if(head==NULL){
// 		return;
// 	}
// 	// ini ada data
// //	else {
// 	//cuma ada 1 data
// 		else if(head==tail){
// //			printf("%d %s : %lf", head->nim,)
// 			free(head);
// 			head=tail=NULL;
// 		}
// 	//jika lebih dari 1 data
// 		else{
// 			struct Mahasiswa *temp = head;
// 			head = head->next;
// 			free(temp);
// 			temp->next = NULL;
// 		}		
// //	}	
// }

// void popTail(){
// 	// tidak ada data di SLL
// 	if(head==NULL){
// 		return;
// 	}
// 	// cuma ada 1 data
// 	else if(head==tail){
// 		free(head);
// 		head=tail=NULL;
// 	}
// 	else{
// 		struct Mahasiswa *curr = head;
// 		while(curr->next != tail){
// 			curr = curr->next;
// 		}
// 		tail= curr;
// 		free(tail->next);
// 		tail->next = NULL;
// 	}
// }

// void popMid(int nim){
// 	//jika tidak ada data
// 	if(head==NULL) return;
// 	//jika data berada di head
// 	else if(head->nim==nim){
// 		popHead();
// 	}
// 	//jika data ada di tail
// 	else if(tail->nim==nim){
// 		popTail();
// 	}
// 	// jika data berada di mid
// 	else {
// 		struct Mahasiswa *curr = head;
// 		while(curr->next!=NULL){
// 			if(curr->next->nim==nim){
// 				break;
// 			}
// 			curr = curr->next;
// 		}
// 		if(curr->next == NULL){
// 			printf("Data tidak ditemukan\n");
// 			return;
// 		}
// 		struct Mahasiswa *temp = curr->next;
// 		curr->next = temp->next;
// 		free(temp);
// 		temp->next= NULL;
// 	}
// }

// void search(int nim){
//     struct Mahasiswa *curr = head;
// 	if(head==NULL) return;
// 	else {
// 		while(curr !=NULL){
// 			if(curr->nim==nim){
// 				break;
// 			}
// 			curr = curr->next;
// 		}
// 		printf("%d %s : %lf\n", curr->nim, curr->name, curr->gpa);
// 	}
// }

// void printAll(){
// 	struct Mahasiswa *curr = head;
// 	while(curr!=NULL){
// 		printf("%d %s : %lf\n", curr->nim, curr->name, curr->gpa);
// 		curr = curr->next;
// 	}
// }

// int main(){
// 	// pushHead(24, "Brian", 4);
// 	// pushHead(22, "Samsudin", 3.5);
// 	// pushHead(26, "Sutarjo", 0);
// 	// pushTail(24, "Brian", 4);
// 	// pushTail(22, "Samsudin", 3.5);
// 	// pushTail(26, "Sutarjo", 0);
	
// 	pushMid(24, "Brian", 4);
// 	pushMid(22, "Samsudin", 3.5);
// 	pushMid(26, "Sutarjo", 0);
// 	pushMid(23, "Siapa", 0);
//     pushMid(29, "Ashraf", 4);
// 	printAll();
// 	printf("POPHead\n");
// 	popHead();
// 	printAll();
// 	printf("POPTail\n");
// 	popTail();
// 	printAll();
// 	printf("POPMid ada\n");
// 	popMid(23);
// 	printAll();
// 	printf("POPMid tidak ada\n");
// 	popMid(27);
// 	printAll();
// 	printf("Search Data\n");
// 	search(22);
	
// 	return 0;
// }

//Basic autocomplete using a Trie
//The trie is really not efficient
//The words should be supplied in a dict.txt file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n {
	struct n *subtrie[26];
	int isEnd;
} trie;

void insert(trie *ele, char *word) {

	trie *root = ele;

	int len = strlen(word);		
	
	for (int i = 0; i < len; i++) {

		trie *curr = ele->subtrie[word[i] % 97];

		if (curr == NULL) {
			curr = malloc (sizeof (trie));
			curr->isEnd = 0;
			for(int i = 0; i < 26; i++) curr->subtrie[i] = NULL;
		}
	
		if(i + 1 == len) curr->isEnd = 1;

		ele->subtrie[word[i] % 97] = curr;
		ele = ele->subtrie[word[i] % 97];
	}

	ele = root;
}

char *append (char *slice, char part) {

	char *str = malloc (sizeof (char) * (strlen (slice) + 2));
	
	int i = 0;
	while (slice[i] != '\0') str[i] = slice[i++];

	str[i++] = part;
	str[i] = '\0';

	return str;
}

void print(trie *ele, char *slice) {

	if (ele == NULL) return;

	if (ele->isEnd) printf("%s\n", slice);

	for (int i = 0; i < 26; i++)
		if(ele->subtrie[i] != NULL)
			print (ele->subtrie[i], append (slice, i + 97));
}

void autocomplete(trie *ele, char *prefix) {

	int len = strlen (prefix);
	for (int i = 0; i < len; i++) ele = ele->subtrie[prefix[i] % 97];
	
	print (ele, prefix);
}

int main() {

	trie n;
	n.isEnd = 0;
	for (int i = 0; i < 26; i++) n.subtrie[i] = NULL;
	
	insert (&n, "sapi"); 
	insert (&n, "asbak"); 
	insert (&n, "astor"); 
	insert (&n, "sapa"); 
	insert (&n, "salju"); 

	char input[100];

	while (1) { 
		printf (">> ");
		scanf ("%s", input);
		autocomplete (&n, input);
	}

	return 0;
}