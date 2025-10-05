def lca(root, v1, v2):
    if root is None:
        return root
    if v1==root.info or v2==root.info:
        return root
    left_lca=lca(root.left,v1,v2)
    right_lca=lca(root.right,v1,v2)
    if left_lca and right_lca:
        return root

    return left_lca if left_lca else right_lca
