/*
 * Copyright 2010-2015 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * Additions Copyright 2016 Espressif Systems (Shanghai) PTE LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

/**
 * @file aws_iot_certifcates.c
 * @brief File to store the AWS certificates in the form of arrays
 */

#ifdef __cplusplus
extern "C" {
#endif

const char aws_root_ca_pem[] = {"-----BEGIN CERTIFICATE-----\n\
MIIE0zCCA7ugAwIBAgIQGNrRniZ96LtKIVjNzGs7SjANBgkqhkiG9w0BAQUFADCB\n\
yjELMAkGA1UEBhMCVVMxFzAVBgNVBAoTDlZlcmlTaWduLCBJbmMuMR8wHQYDVQQL\n\
ExZWZXJpU2lnbiBUcnVzdCBOZXR3b3JrMTowOAYDVQQLEzEoYykgMjAwNiBWZXJp\n\
U2lnbiwgSW5jLiAtIEZvciBhdXRob3JpemVkIHVzZSBvbmx5MUUwQwYDVQQDEzxW\n\
ZXJpU2lnbiBDbGFzcyAzIFB1YmxpYyBQcmltYXJ5IENlcnRpZmljYXRpb24gQXV0\n\
aG9yaXR5IC0gRzUwHhcNMDYxMTA4MDAwMDAwWhcNMzYwNzE2MjM1OTU5WjCByjEL\n\
MAkGA1UEBhMCVVMxFzAVBgNVBAoTDlZlcmlTaWduLCBJbmMuMR8wHQYDVQQLExZW\n\
ZXJpU2lnbiBUcnVzdCBOZXR3b3JrMTowOAYDVQQLEzEoYykgMjAwNiBWZXJpU2ln\n\
biwgSW5jLiAtIEZvciBhdXRob3JpemVkIHVzZSBvbmx5MUUwQwYDVQQDEzxWZXJp\n\
U2lnbiBDbGFzcyAzIFB1YmxpYyBQcmltYXJ5IENlcnRpZmljYXRpb24gQXV0aG9y\n\
aXR5IC0gRzUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCvJAgIKXo1\n\
nmAMqudLO07cfLw8RRy7K+D+KQL5VwijZIUVJ/XxrcgxiV0i6CqqpkKzj/i5Vbex\n\
t0uz/o9+B1fs70PbZmIVYc9gDaTY3vjgw2IIPVQT60nKWVSFJuUrjxuf6/WhkcIz\n\
SdhDY2pSS9KP6HBRTdGJaXvHcPaz3BJ023tdS1bTlr8Vd6Gw9KIl8q8ckmcY5fQG\n\
BO+QueQA5N06tRn/Arr0PO7gi+s3i+z016zy9vA9r911kTMZHRxAy3QkGSGT2RT+\n\
rCpSx4/VBEnkjWNHiDxpg8v+R70rfk/Fla4OndTRQ8Bnc+MUCH7lP59zuDMKz10/\n\
NIeWiu5T6CUVAgMBAAGjgbIwga8wDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8E\n\
BAMCAQYwbQYIKwYBBQUHAQwEYTBfoV2gWzBZMFcwVRYJaW1hZ2UvZ2lmMCEwHzAH\n\
BgUrDgMCGgQUj+XTGoasjY5rw8+AatRIGCx7GS4wJRYjaHR0cDovL2xvZ28udmVy\n\
aXNpZ24uY29tL3ZzbG9nby5naWYwHQYDVR0OBBYEFH/TZafC3ey78DAJ80M5+gKv\n\
MzEzMA0GCSqGSIb3DQEBBQUAA4IBAQCTJEowX2LP2BqYLz3q3JktvXf2pXkiOOzE\n\
p6B4Eq1iDkVwZMXnl2YtmAl+X6/WzChl8gGqCBpH3vn5fJJaCGkgDdk+bW48DW7Y\n\
5gaRQBi5+MHt39tBquCWIMnNZBU4gcmU7qKEKQsTb47bDN0lAtukixlE0kF6BWlK\n\
WE9gyn6CagsCqiUXObXbf+eEZSqVir2G3l6BFoMtEMze/aiCKm0oHw0LxOXnGiYZ\n\
4fQRbxC1lfznQgUy286dUV4otp6F01vvpX1FQHKOtw5rDgb7MzVIcbidJ4vEZV8N\n\
hnacRHr2lVz2XTIIM6RUthg/aFzyQkqFOFSDX9HoLPKsEdao7WNq\n\
-----END CERTIFICATE-----\n"};

const char certificate_pem_crt[] = {"-----BEGIN CERTIFICATE-----\n\
MIIDWjCCAkKgAwIBAgIVANTMLENLTJGDFXsITyMKkJqOQWW7MA0GCSqGSIb3DQEB\n\
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t\n\
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0xOTA0MTQwMDE3\n\
MjNaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh\n\
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCqi4KVh1/ouLt7Tn7z\n\
M+QyYbX5Jcmfr4mOgXKRIT711aemHkrB7T2TdT5znvfVBJRCi2P6yNFqVQynYq4K\n\
ilRzJeAYCvuFg5RKGIkFJ1YSaFk7IzY5tXfWiH5Rlh9UUenZSg1zAU24F2XG1snx\n\
xzyp5z6SLXwsjypQoGKM6bggdYrXmjYQTsCQpHqDb0mMRXp0Fim2emeOZvyoN4/Q\n\
fFZKQk4Ulwxla9DFCzItHaDYlsbBGcEHByq9BaHO8Zg+RVuB1j18g7q3aSWWuiDg\n\
9Oe9pCvAJZ/8K9aUghNnhu2Jsxyc0uZ1gSaEFfYXnpelCaRs4JBdBn+GNX5Eb7N0\n\
4VY3AgMBAAGjYDBeMB8GA1UdIwQYMBaAFFeCeOrp3D5lMR01Hy4+OXaUKt+dMB0G\n\
A1UdDgQWBBReyUOIMjG0UE7D2iRlo7nGh66jEDAMBgNVHRMBAf8EAjAAMA4GA1Ud\n\
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEApaie4SrdwdtkjsyvxpnPIz8V\n\
To86sHr5/9yiFdBAabVxZulKsHUj4/+SNjsET7CgXby6yZvo7ezuGPN7WJKYaR7g\n\
7bz0Jl1oIBbfkI5tw5azF0UGhKEUSoAPiw/TvV4eQPw1xYkDhALAlwB34SUi1dzd\n\
TnBHpeVARoBFlVOKluxMtK8b/DwW89nHh28rGHkofiw8t/Ezj95osn3m0yAHaAsY\n\
ye6eOBoVcqwzU8M1ydtl/yMTb3tO213U48V/onk5WSuDlHuNsXnTYV9lm/vObXR2\n\
um9BQmy3o3cYVTVRdd0i4I2lBz+8+HtlDLhmZW6KeT5FGRIXA5m4fquhYf3gfw==\n\
-----END CERTIFICATE-----\n"};

const char private_pem_key[] = {"-----BEGIN RSA PRIVATE KEY-----\n\
MIIEogIBAAKCAQEAqouClYdf6Li7e05+8zPkMmG1+SXJn6+JjoFykSE+9dWnph5K\n\
we09k3U+c5731QSUQotj+sjRalUMp2KuCopUcyXgGAr7hYOUShiJBSdWEmhZOyM2\n\
ObV31oh+UZYfVFHp2UoNcwFNuBdlxtbJ8cc8qec+ki18LI8qUKBijOm4IHWK15o2\n\
EE7AkKR6g29JjEV6dBYptnpnjmb8qDeP0HxWSkJOFJcMZWvQxQsyLR2g2JbGwRnB\n\
BwcqvQWhzvGYPkVbgdY9fIO6t2kllrog4PTnvaQrwCWf/CvWlIITZ4btibMcnNLm\n\
dYEmhBX2F56XpQmkbOCQXQZ/hjV+RG+zdOFWNwIDAQABAoIBAA6omRvDHAJDxpGN\n\
qKm8vxN5hIuarN7V1qvyAmfpBKFasOM9XU2X16ASBsEnW8PqddfWZUyL8DwEfWbx\n\
u2Xah/GxwrYuU3ohWiCYRUa1H9fLMkg7+ZAyQc+lwb2/eofj1oa/r7I/3W9CS5Qw\n\
qADpEBTGdIFZ+X9W+tsdPftAp3vamoUjfbb02WgcrbAmljP/PuSb+ll47c4M2nS5\n\
nsm1nymgtUACxNAVCXh+mqAI+UqSUfbL8O8f+/VtHWSqSH0pygAITC/n6Wz2+Utk\n\
PJ/RWf8kMuQZRG2bYAtNLc2wJ0uBCBzT4h10NMgvdszHx7lsAvRbTK1MK3WHwSed\n\
lhe8xXkCgYEA4OvOBn1PZ5qoJ6TUM4i1wItfUDhBjKul+J/Ky8Jvgp5Ab47sahLX\n\
33OArbxp0zoBZuG1da6lZ9wRybEE0hw0kBqGVFEQUMqsREUJKJ3V6FTXys+tOHyG\n\
M9FESo5j37rSBuqiG4Uto/HOfPpMdwQ5/Y3aeuXrqFtj43vqdn8pPr0CgYEAwhw+\n\
N7v27GQZPJvJeIPtZXngTHPBuipNYH191JUZMbB3iSQXk8lWHD3EupVZtqTrD+1N\n\
fg99TEpLSptH7r3vM8G8sx/nJp/HXdNqtXQRaunP4Gc2+51JfHdKRw8hGbsMuxUJ\n\
cE2c/HyLao+AXni9Rjw5EsG8JB8svTcDOqCaogMCgYBUgWQL3iLqSxooou4zWobn\n\
C7ZI3ooKPyeBjQ/VlHzu92RARdOfWusOgkfzfpnICcAjFmRmDbMJnY51V/P2uTAq\n\
gDy+CyL1J+CnWcTCJOMMgmv9QB/V3DtT1qkw1eTCV1+3x4oWiugF88DgBe6avNTI\n\
5fYTPLVYsNWLz6/cy5QEhQKBgFkmx5ypg9tGjiC8HGhxj1MQCuiSMePjEe7DNEuy\n\
vwOHXR9rqDiEPDx0Uiqv9ahhTmTeRL0lOBMV/Eaj0wHf0kEfNh+/A1dGAzcgpt34\n\
FRfZk1Qpk6M0tk+oKkFAvZ8nvc0e+FrQCs4cFZw3lGnPYn8jocLvoA2nE9FDtwPy\n\
R5MpAoGAbIe8s0Ky4teh0jTLumlBzi351YX+qxpRNLhBqOFppcGOY2QAn3JXt1Td\n\
6q5C/WA/pSksmIOrzkNZYDCPvU4fSgwYLFVMOtCIgPOBWiAuxhIQwUJRlGCRRjqQ\n\
HY9Hx0PU6AcxRK0T44eh6gGfpZE2eaCpMHP3zVVJfLC8GRaLPA8=\n\
-----END RSA PRIVATE KEY-----\n"};


#ifdef __cplusplus
}
#endif
