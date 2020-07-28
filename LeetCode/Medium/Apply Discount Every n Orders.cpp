class Cashier {
public:
    int count,dis,N;
    unordered_map<int,int>pri;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        dis=discount;
        N=n;
        count=0;
        for(int i=0;i<products.size();i++)
            pri[products[i]]=prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double cost=0;
        for(int i=0;i<product.size();i++)
            cost+=(pri[product[i]]*amount[i]);
        
        if(count%N==0)
           return cost-((cost*dis)/100);    
        return cost;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */