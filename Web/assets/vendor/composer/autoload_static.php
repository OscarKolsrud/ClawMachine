<?php

// autoload_static.php @generated by Composer

namespace Composer\Autoload;

class ComposerStaticInit16a726835146a3227ba30467f1681c9f
{
    public static $prefixLengthsPsr4 = array (
        'S' => 
        array (
            'Stripe\\' => 7,
        ),
    );

    public static $prefixDirsPsr4 = array (
        'Stripe\\' => 
        array (
            0 => __DIR__ . '/..' . '/stripe/stripe-php/lib',
        ),
    );

    public static function getInitializer(ClassLoader $loader)
    {
        return \Closure::bind(function () use ($loader) {
            $loader->prefixLengthsPsr4 = ComposerStaticInit16a726835146a3227ba30467f1681c9f::$prefixLengthsPsr4;
            $loader->prefixDirsPsr4 = ComposerStaticInit16a726835146a3227ba30467f1681c9f::$prefixDirsPsr4;

        }, null, ClassLoader::class);
    }
}
