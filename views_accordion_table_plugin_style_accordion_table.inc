<?php
/**
 * Created by PhpStorm.
 * User: Eugeniy
 * Date: 26.01.2016
 * Time: 11:10
 */

/**
 * Style plugin to render each item as a row in a table.
 *
 * @ingroup views_style_plugins
 */
class views_accordion_table_plugin_style_accordion_table extends views_plugin_style_table {
    function option_definition()
    {
        $options = parent::option_definition();
        $options['accordion_table'] = array('default' => array());
        return $options;
    }

    /**
     * Render the given style.
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);
        $columns = $form['columns'];
        $form['accordion_table'] = array(
            '#type' => 'fieldset',
            '#title' => t('Accordion table settings'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#tree' => true,
            '#weight' => -1
        );
        $form['accordion_table']['fields'] = array(
            '#type' => 'fieldset',
            '#title' => t('Fields'),
            '#collapsible' => TRUE,
            '#collapsed' => FALSE,
            '#tree' => true,
        );
        foreach ($columns as $field => $column) {
            $safe = str_replace(array('][', '_', ' '), '-', $field);
            // the $id of the column for dependency checking.
            $id = 'edit-style-options-columns-' . $safe;
            $form['accordion_table']['fields'][$field] = array(
                '#type' => 'checkbox',
                '#default_value' => !empty($this->options['accordion_table']['fields'][$field]),
                '#title' => $form['info'][$field]['name']['#markup'],
                '#dependency' => array(
                    $id => array($field),
                ),
            );
        }
    }

    function options_submit(&$form, &$form_state){
        foreach($form_state['values']['style_options']['accordion_table']['fields'] as $filed => &$value)
        {
            if($form_state['values']['style_options']['columns'][$filed] != $filed)
                $value = null;
        }
        unset($value);
    }
}