package com.datastructures.disjointset;

public class DisjointSet {
    private Integer[] parent;
    private Integer[] rank;

    public DisjointSet(int size) {
        this.parent = new Integer[size];
        this.rank = new Integer[size];
    }

    public void makeSet(int i) {
        if (i < 0 || i >= this.parent.length)
            throw new ArrayIndexOutOfBoundsException();
        this.parent[i] = i;
        this.rank[i] = 0;
    }

    public Integer find(int i) {
        if (i < 0 || i >= this.parent.length)
            throw new ArrayIndexOutOfBoundsException();
        if (i != this.parent[i])
            this.parent[i] = find(parent[i]);
        return this.parent[i];
    }

    public void union(int i, int j) {
        Integer iID = find(i);
        Integer jID = find(j);
        if (iID.equals(jID)) return;
        if (this.rank[iID] > this.rank[jID]) {
            this.parent[jID] = iID;
        } else {
            this.parent[iID] = jID;
            if (this.rank[iID].equals(this.rank[jID]))
                this.rank[jID] = this.rank[jID] + 1;
        }
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < this.parent.length; i++) {
            stringBuilder.append(i).append(": ").append(this.parent[i]).append('\n');
        }
        return stringBuilder.toString();
    }
}
