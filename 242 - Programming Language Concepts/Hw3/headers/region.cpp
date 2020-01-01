#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "region.h"

using namespace std;

Region::Region(const int* f, const int* s) {
	Bvh * new_bvh = new Bvh(NULL, NULL, NULL, f, s, NULL); //left,right,parent,int[3],int[3],data
	root = new_bvh;

}
Region::Region(const Region& a) {
	if (a.root == NULL)
		root = NULL;
	else
		root = copy_helper(a.root);
	parent_helper(root);
}

Region::Bvh* Region::copy_helper(const Bvh * rhs) {
	if (rhs == NULL)
		return NULL;
	Bvh * new_bvh = new Bvh();
	new_bvh->x1 = rhs->x1;
	new_bvh->x2 = rhs->x2;
	new_bvh->y1 = rhs->y1;
	new_bvh->y2 = rhs->y2;
	new_bvh->z1 = rhs->z1;
	new_bvh->z2 = rhs->z2;

	new_bvh->data = rhs->data;

	new_bvh->left = copy_helper(rhs->left);
	new_bvh->right = copy_helper(rhs->right);
	return new_bvh;
}

void Region::parent_helper(Bvh * r) {
	if (r == NULL) {
		return;
	}
	if (r->left) {
		r->left->parent = r;
		parent_helper(r->left);
	}
	if (r->right) {
		r->right->parent = r;
		parent_helper(r->right);
	}
}

Region::~Region() {
	destruction_helper(root);
}
void Region::destruction_helper(Bvh *r) {
	if (r != NULL) {
		destruction_helper(r->left);
		destruction_helper(r->right);
		delete r;
	}
}
int Region::getMinBorder(char a) const {

	if (a == 'x')
		return root->x1;
	else if (a == 'y')
		return root->y1;
	else
		return root->z1;
}
int Region::getMaxBorder(char a) const {
	if (a == 'x')
		return root->x2;
	else if (a == 'y')
		return root->y2;
	else
		return root->z2;
}
void Region::placePokemon(const Pokemon& pokemon, int x, int y, int z) {
	Bvh* tmp = root;

	while (true) {
		if (!(tmp->x1 == x && tmp->x2 == x)) {
			if (x <= (tmp->x2 + tmp->x1) / 2) {
				if (tmp->left == NULL) {
					tmp->left = new Bvh();
					tmp->left->x1 = tmp->x1;
					tmp->left->x2 = (tmp->x2 + tmp->x1) / 2;
					tmp->left->y1 = tmp->y1;
					tmp->left->y2 = tmp->y2;
					tmp->left->z1 = tmp->z1;
					tmp->left->z2 = tmp->z2;
					tmp->left->parent = tmp;
				}

				tmp = tmp->left;
			}

			else {
				if (tmp->right == NULL) {
					tmp->right = new Bvh();
					tmp->right->x1 = (tmp->x2 + tmp->x1) / 2 + 1;
					tmp->right->x2 = tmp->x2;
					tmp->right->y1 = tmp->y1;
					tmp->right->y2 = tmp->y2;
					tmp->right->z1 = tmp->z1;
					tmp->right->z2 = tmp->z2;
					tmp->right->parent = tmp;
				}

				tmp = tmp->right;
			}
		}

		if (!(tmp->y1 == y && tmp->y2 == y)) {
			if (y <= (tmp->y2 + tmp->y1) / 2) {
				if (tmp->left == NULL) {
					tmp->left = new Bvh();
					tmp->left->x1 = tmp->x1;
					tmp->left->x2 = tmp->x2;
					tmp->left->y1 = tmp->y1;
					tmp->left->y2 = (tmp->y2 + tmp->y1) / 2;
					tmp->left->z1 = tmp->z1;
					tmp->left->z2 = tmp->z2;
					tmp->left->parent = tmp;
				}

				tmp = tmp->left;
			}

			else {
				if (tmp->right == NULL) {
					tmp->right = new Bvh();
					tmp->right->x1 = tmp->x1;
					tmp->right->x2 = tmp->x2;
					tmp->right->y1 = (tmp->y2 + tmp->y1) / 2 + 1;
					tmp->right->y2 = tmp->y2;
					tmp->right->z1 = tmp->z1;
					tmp->right->z2 = tmp->z2;
					tmp->right->parent = tmp;
				}

				tmp = tmp->right;
			}
		}

		if (!(tmp->z1 == z && tmp->z2 == z)) {
			if (z <= (tmp->z2 + tmp->z1) / 2) {
				if (tmp->left == NULL) {
					tmp->left = new Bvh();
					tmp->left->x1 = tmp->x1;
					tmp->left->x2 = tmp->x2;
					tmp->left->y1 = tmp->y1;
					tmp->left->y2 = tmp->y2;
					tmp->left->z1 = tmp->z1;
					tmp->left->z2 = (tmp->z2 + tmp->z1) / 2;
					tmp->left->parent = tmp;
				}

				tmp = tmp->left;
			}

			else {
				if (tmp->right == NULL) {
					tmp->right = new Bvh();
					tmp->right->x1 = tmp->x1;
					tmp->right->x2 = tmp->x2;
					tmp->right->y1 = tmp->y1;
					tmp->right->y2 = tmp->y2;
					tmp->right->z1 = (tmp->z2 + tmp->z1) / 2 + 1;
					tmp->right->z2 = tmp->z2;
					tmp->right->parent = tmp;
				}

				tmp = tmp->right;
			}
		}

		if ((tmp->x1 == x && tmp->x2 == x) && (tmp->y1 == y && tmp->y2 == y)
				&& (tmp->z1 == z && tmp->z2 == z)) {
			tmp->data = const_cast<Pokemon*>(&pokemon);
			break;
		}
	}

}
Pokemon& Region::operator()(int x, int y, int z) {
	Bvh* tmp = root;
	while (true) {
		if (!(tmp->x1 == x && tmp->x2 == x)) {
			if (x <= (tmp->x2 + tmp->x1) / 2) {
				tmp = tmp->left;
			}

			else {
				tmp = tmp->right;
			}
		}

		if (!(tmp->y1 == y && tmp->y2 == y)) {
			if (y <= (tmp->y2 + tmp->y1) / 2) {
				tmp = tmp->left;
			}

			else {
				tmp = tmp->right;
			}
		}

		if (!(tmp->z1 == z && tmp->z2 == z)) {
			if (z <= (tmp->z2 + tmp->z1) / 2) {
				tmp = tmp->left;
			}

			else {
				tmp = tmp->right;
			}
		}

		if ((tmp->x1 == x && tmp->x2 == x) && (tmp->y1 == y && tmp->y2 == y)
				&& (tmp->z1 == z && tmp->z2 == z)) {


			return *(tmp->data);
		}
	}

}

int Region::count_helper(Bvh* bvh, int x1, int x2, int y1, int y2, int z1,
		int z2) const {
	if (bvh == NULL) {
		return 0;
	}

	if (bvh->data != NULL && bvh->x1 >= x1 && bvh->x2 <= x2 && bvh->y1 >= y1
			&& bvh->y2 <= y2 && bvh->z1 >= z1 && bvh->z2 <= z2) {
		return 1;
	}

	return count_helper(bvh->left, x1, x2, y1, y2, z1, z2)
			+ count_helper(bvh->right, x1, x2, y1, y2, z1, z2);
}

int Region::getPokemonCount(const int c1[3], const int c2[3]) const {
	return count_helper(root, c1[0], c2[0], c1[1], c2[1], c1[2], c2[2]);
}

Region::Bvh* Region::crop_helper(Bvh* bvh, int x1, int x2, int y1, int y2,
		int z1, int z2) const {
	if (bvh == NULL)
		return NULL;

	if (bvh->x1 == x1 && bvh->x2 == x2 && bvh->y1 == y1 && bvh->y2 == y2
			&& bvh->z1 == z1 && bvh->z2 == z2) {
		return bvh;
	}

	Bvh* tmp = crop_helper(bvh->left, x1, x2, y1, y2, z1, z2);
	if (tmp != NULL)
		return tmp;

	tmp = crop_helper(bvh->right, x1, x2, y1, y2, z1, z2);
	return tmp;

}

Region Region::crop(const int c1[3], const int c2[3]) const {
	Bvh* tmp = crop_helper(root, c1[0], c2[0], c1[1], c2[1], c1[2], c2[2]);
	Region* region = new Region(c1,c2);
	region->root = tmp;
	return *region;
}
void Region::patch(Region) {

}
Region& Region::operator=(const Region&) {

}
