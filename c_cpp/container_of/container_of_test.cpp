#include <stdlib.h>
#include <gtest/gtest.h>
#include "container_of.h"

using namespace std;

struct TestNode {
	int a;
	char b;
	double c;
	void *ptr;
	TestNode *nxt;
};

class ContainerOfTest : public ::testing::Test {
protected:
	virtual void SetUp() {
		node = (TestNode*) malloc(sizeof(TestNode));
		node->a = 5566;
		node->b = 'a';
		node->c = 55.66;
		node->ptr = NULL;
		node->nxt = node;

		node2 = (TestNode*) malloc(sizeof(TestNode));
	}
	virtual void TearDown() {
		free(node);
		free(node2);
	}

	TestNode *node;
	TestNode *node2;
};

TEST_F(ContainerOfTest, BasicTest)
{
	EXPECT_EQ(node, container_of(&node->a, TestNode, a));
	EXPECT_EQ(node, container_of(&node->b, TestNode, b));
	EXPECT_EQ(node, container_of(&node->c, TestNode, c));
	EXPECT_EQ(node, container_of(&node->ptr, TestNode, ptr));
	EXPECT_EQ(node, container_of(&node->nxt, TestNode, nxt));

	EXPECT_NE(node2, container_of(&node->nxt, TestNode, nxt));
}
