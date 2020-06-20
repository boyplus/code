class Main{
	public static void main(String[] args){
		Solution s = new Solution();
		TreeNode t = new TreeNode(1);
		t.left = new TreeNode(2);
		t.right = new TreeNode(3);
		t.left.left = new TreeNode(4);
		t.left.right = new TreeNode(5);

		int ans = s.diameterOfBinaryTree(t);
		System.out.println(ans);
	}
}
class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode() {}
	TreeNode(int val) { this.val = val; }
	TreeNode(int val, TreeNode left, TreeNode right) {
		this.val = val;
		this.left = left;
		this.right = right;
	}
}

class Solution {
	int ans;
	public int dfs(TreeNode u){
		if(u == null) return 0;
		if(u.left == null){
			if(u.right == null){
				return 0;
			}
		}
		int left = 0,right = 0;
		if(u.left != null){
			left = dfs(u.left)+1;
		}
		if(u.right != null){
			right = dfs(u.right)+1;	
		}
		ans = Math.max(ans,left+right);
		return Math.max(left,right);

	}
	public int diameterOfBinaryTree(TreeNode root){
		int height = dfs(root);
		return ans;
	}
}