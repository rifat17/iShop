#ifndef PRODUCT_INFO_H
#define PRODUCT_INFO_H


class Product_Info
{
    public:
        Product_Info( int = 0, int = 0 );

        void setCost( int );
        void setQuantity( int );
        void setProductInfo();

        int getCost();
        int getQuantity();

        void displayPdoductInfo();

        void setProductCostForCustomer();
        void setProductQuantityForCustomer();

        virtual ~Product_Info();
        Product_Info(const Product_Info& other);
        Product_Info& operator=(const Product_Info& other);

    protected:

    private:
        int _cost;
        int _quantity;
};

#endif // PRODUCT_INFO_H
