<?php
/**
 * Created by PhpStorm.
 * User: Eugeniy
 * Date: 26.01.2016
 * Time: 11:04
 */

/**
 * Implements hook_views_plugins().
 */
function views_accordion_table_views_plugins(){
    $path = drupal_get_path('module', 'views_accordion_table');

    return array(
        'module' => 'views_accordion_table',
        'style' => array(
            'extended_table' => array(
                'title' => t('Accordion Table'),
                'help' => t('Display the view as accordion table.'),
                'handler' => 'views_accordion_table_plugin_style_accordion_table',
                'theme' => 'views_accordion_table',
                //'theme path' => $path.'/templates',
                //'theme file' => null, // problems!!! hook_theme_registry_alter
                'path' => $path,
                'parent' => 'default',
                'uses row plugin' => FALSE,
                'uses row class' => TRUE,
                'uses fields' => TRUE,
                'uses options' => TRUE,
                'type' => 'normal',
            ),
        ),
    );
}