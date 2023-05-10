#pragma once

#include <iostream>
#include "Invoice.h"

class InvoiceTest {
public:
    void runTests() {
        testEmptyInvoice();
        testInvoiceWithOneItem();
        testInvoiceWithMultipleItems();
        testNegativeQuantity();
        testNegativePrice();
    }

private:
    void testEmptyInvoice() {
        Invoice invoice;
        if (invoice.getSubtotal() != 0) {
            std::cout << "Test empty invoice failed: subtotal should be 0" << std::endl;
        }
        if (invoice.getTax() != 0) {
            std::cout << "Test empty invoice failed: tax should be 0" << std::endl;
        }
        if (invoice.getTotal() != 0) {
            std::cout << "Test empty invoice failed: total should be 0" << std::endl;
        }
    }

    void testInvoiceWithOneItem() {
        Invoice invoice;
        invoice.addItem("Item 1", 1, 10.0);
        if (invoice.getSubtotal() != 10.0) {
            std::cout << "Test invoice with one item failed: subtotal should be 10.0" << std::endl;
        }
        if (invoice.getTax() != 0.5) {
            std::cout << "Test invoice with one item failed: tax should be 0.5" << std::endl;
        }
        if (invoice.getTotal() != 10.5) {
            std::cout << "Test invoice with one item failed: total should be 10.5" << std::endl;
        }
    }

    void testInvoiceWithMultipleItems() {
        Invoice invoice;
        invoice.addItem("Item 1", 1, 10.0);
        invoice.addItem("Item 2", 2, 5.0);
        if (invoice.getSubtotal() != 20.0) {
            std::cout << "Test invoice with multiple items failed: subtotal should be 20.0" << std::endl;
        }
        if (invoice.getTax() != 1.0) {
            std::cout << "Test invoice with multiple items failed: tax should be 1.0" << std::endl;
        }
        if (invoice.getTotal() != 21.0) {
            std::cout << "Test invoice with multiple items failed: total should be 21.0" << std::endl;
        }
    }

    void testNegativeQuantity() {
        Invoice invoice;
        invoice.addItem("Item 1", -1, 10.0);
        if (invoice.getSubtotal() != 0) {
            std::cout << "Test negative quantity failed: subtotal should be 0" << std::endl;
        }
        if (invoice.getTax() != 0) {
            std::cout << "Test negative quantity failed: tax should be 0" << std::endl;
        }
        if (invoice.getTotal() != 0) {
            std::cout << "Test negative quantity failed: total should be 0" << std::endl;
        }
    }

    void testNegativePrice() {
        Invoice invoice;
        invoice.addItem("Item 1", 1, -10.0);
        if (invoice.getSubtotal() != 0) {
            std::cout << "Test negative price failed: subtotal should be 0" << std::endl;
        }
        if (invoice.getTax() != 0) {
            std::cout << "Test negative price failed: tax should be 0" << std::endl;
